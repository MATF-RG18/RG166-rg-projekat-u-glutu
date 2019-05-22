#include "variables.h"


static int window_width, window_height;


static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void jump();
static void cone_move(int);
static void make_cone(int);
static void move_level();
static void on_timer(int value);
void output(int x, int y, char* string);

static int random_position(int);

bool collision(float, float);
char score_output[256]; //String u koji cuvamo skor

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);


    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    glutFullScreen();
    
    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0.5, 0.5, 1, 1);
    glEnable(GL_DEPTH_TEST);
    
    //Omogucavamo osvetljenje
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    
    //Postavljamo osvetljenje scene
    set_light();
    
    //Pokrecemo nivo
    glutTimerFunc(1000/60, on_timer, 0);
    glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        /* Zavrsava se program. */
        exit(0);
        break;
    case 'r':
        //Restartuje ceo nivo tj. vraca sve vrednosti na pocetne
        for(int i=0; i<COIN_COUNT; i++){
            coin_coll[i] = false;
        }
        score = 0;
        translate_level = 10;
        player_posX = -6.0;
        player_posY = -4.0;
        jump_count = true;
        coll = false;
        posMax = -1.0;
        posMin = -4.0;
        endgame = false;
        break;
    case 'p':
        //Pauzira nivo
        jump_speed = 0;
        fall_speed = 0;
        translate_coef = 0;
        break;
    case 'g':
        //Nastavljamo sa igrom nakon pauze
        jump_speed = 0.175;
        fall_speed = 0.2;
        translate_coef = 0.1;
        break;
    case 'w':
        //Skakanje
        w_pressed = true;
        break;
    }
}

static void on_reshape(int width, int height)
{
    /* Pamte se sirina i visina prozora. */
    window_width = width;
    window_height = height;
}

//Izbacivanje teksta na ekran
void output(int x, int y, char *string)
{
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
    }
}

void output_endgame(int x, int y, char *string)
{
    glColor3f(1.0, 1.0, 1.0);
    glRasterPos2f(x, y);
    int len, i;
    len = (int)strlen(string);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
    }
}

//Pomeranje nivoa

static void on_timer(int value){
    
    translate_level -= translate_coef;
    score_translate_add += translate_coef;
    //Kada score_translate_add dodje do 1 onda se doda 5 boda na skor
    if(score_translate_add >= 1.0 && score_translate_add <= 1.5){
        score += 5;
        score_translate_add = 0;
    }
    
    //Skakanje
    if(w_pressed){
        if(jump_count == true && can_jump == true && player_posY >= posMin){
                posMin = -4.0;
                can_jump == false;
                jump();
                
                if(player_posY == -4.0){
                    posMax = -1.0;
                    w_pressed = false;
                }
            }
            //Ukoliko igrac nije vec u skoku onda skace
        else if(jump_count == true)
            jump();
        else{
            //Pocinje pad
            if(player_posY >= posMin && jump_count == false)
                player_posY -= fall_speed;
            //Ukoliko igrac dodje do min visine (ili je prodje)
            //visina igraca se postavlja na min visinu
            else if(player_posY <= posMin){
                player_posY = posMin;
                jump_count = true;
                posMax = -1.0;
                w_pressed = false;
            }
        }
    }
    
    //Slobodan pad
    if((player_posY >= posMin) && free_fall_active)
        player_posY -= fall_speed;
    if(player_posY <= posMin && free_fall_active){
        player_posY = posMin;
        jump_count = true;
        free_fall_active = false;
    }
    
    glutPostRedisplay();
    glutTimerFunc(1000/60, on_timer, 0);
    
}

//Skok
static void jump(){
	//pocinje skok
    if(player_posY <= posMax && jump_count == true){
		player_posY += jump_speed;
	}
	//Igrac je dosao do max visine
	else if(player_posY >= posMax){
		jump_count = false;
	}
}

static int random_position(int value){
	srand(time(NULL));
	if(rand()%value - 8 < player_posY)
		return player_posY;
	else
		return rand()%value - 8;
}


static void on_display(void)
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //Postavljanje kamere
    glViewport(0, 0, window_width, window_height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            1, 25);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            0, 0, 15,
            0, 0, 0,
            0, 1, 0 
        );
    
    //Zemlja
    glPushMatrix();
        glScalef(100,4,2);
        glTranslatef(0,-1.66,0);
        ground_light();
        glutSolidCube(1);
    glPopMatrix();
    
    //Igrac
    glPushMatrix();
        glTranslatef(player_posX, player_posY, 0);
        player_light();
        glutSolidCube(1);
    glPopMatrix();
    
    //Kliping ravan koja se nalazi van ekrana, da se ne bi ispisivao ceo nivo
    double clip_plane[] = {-2, 0, 0, 0};
    
    glPushMatrix();
    glTranslatef(25,0,0);
    glClipPlane(GL_CLIP_PLANE0, clip_plane);
    glPopMatrix();
    glEnable(GL_CLIP_PLANE0);
    
    //Nivo
    glPushMatrix();
         if(coll){
             //nakon detekcije kolizije restartuje se nivo
             for(int i=0; i<COIN_COUNT; i++){
             coin_coll[i] = false;
             }
             score = 0;
             translate_level = 10;
             player_posX = -6.0;
             player_posY = -4.0;
             jump_count = true;
             coll = false;
             posMax = -1.0;
             posMin = -4.0;
             jump_speed = 0;
             fall_speed = 0;
             translate_coef = 0;
             endgame = false;
         }
    
        if(endgame){
            //Predjen nivo
            translate_coef = 0;
            jump_speed = 0;
            glDisable(GL_LIGHTING);
            glDisable(GL_LIGHT0);
            output(0, 4, "YOU WIN!");
            glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        }
        glColor3f(1,0,0);
        glTranslatef(translate_level,0,0);
        draw_lvl();
    glPopMatrix();
    
    glDisable(GL_CLIP_PLANE0);
    
    //Ispisivanje skora u gornjem desnom uglu
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
        output(12.5,8.5, "Score: ");
        sprintf(score_output, "%d", score);
        output(14.5, 8.5, score_output);     
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    glutPostRedisplay();
    glutSwapBuffers();
}
