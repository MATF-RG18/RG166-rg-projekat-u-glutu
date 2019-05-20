#include "variables.h"


static int window_width, window_height;


static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void jump();
static void cone_move(int);
static void make_cone(int);
static void move_level();
void output(int x, int y, char* string);

static int random_position(int);

bool collision(float, float);

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
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);
    
    glutTimerFunc(0, move_level, 0);
   // glutTimerFunc(0, free_fall, 0);
    /* Program ulazi uglavnu petlju. */
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
        translate_level = 10;
        player_posX = -6.0;
        player_posY = -4.0;
        jump_count = true;
        coll = false;
        posMax = -1.0;
        posMin = -4.0;
        break;
    case 'p':
        jump_speed = 0;
        fall_speed = 0;
        translate_coef = 0;
        break;
    case 'g':
        jump_speed = 0.15;
        fall_speed = 0.175;
        translate_coef = 0.075;
        break;
    case 'w':
        if(jump_count == true && can_jump == true && player_posY == posMin){
            posMin = -4.0;
            can_jump == false;
            glutTimerFunc(0,jump,0);
            
            if(player_posY == -4.0)
                posMax = -1.0;
        } else if(jump_count == true && player_posY == posMin)
            glutTimerFunc(0,jump, 0);
        break;
    }
}

static void on_reshape(int width, int height)
{
    /* Pamte se sirina i visina prozora. */
    window_width = width;
    window_height = height;
}

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
 
static void move_level(){
    translate_level -= translate_coef;
    glutPostRedisplay();
    glutTimerFunc(1000/60, move_level, 0);
    
}

static void jump(){
	if(player_posY <= posMax && jump_count == true){
		player_posY += jump_speed;
	}
	else if(player_posY >= posMax){
		jump_count = false;
	}
	
	if(player_posY >= posMin && jump_count == false)
		player_posY -= fall_speed;
	else if(player_posY <= posMin){
		player_posY = posMin;
		jump_count = true;
		return;
	}
    
	glutPostRedisplay();
	glutTimerFunc(1000/60, jump, 0);
}

static void free_fall(){
    if((player_posY >= posMin) && (coll == false) && (jump_count == false))
        player_posY -= fall_speed;
    else if(player_posY <= posMin){
        player_posY = posMin;
        jump_count = true;
    }
    
    glutPostRedisplay();
	glutTimerFunc(1000/60, free_fall, 0);
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
    
//     GLfloat light_position[] = {1,1,1,0};
//     GLfloat light_ambient[] = {0.0,0.0,0.0,1};
//     GLfloat light_diffuse[] = {0.7,0.7,0.7,1};
//     GLfloat light_specular[] = {0.9,0.9,0.9,1};
//     
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
    
    /*glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
   /* /* glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    GLfloat ambient_coeffs_floor[] = { 0, 0, 1, 1 };
    GLfloat diffuse_coeffs_floor[] = { 0.0, 0.0, 0.8, 1 };
    GLfloat specular_coeffs_floor[] = { 1, 1, 1, 1 };
    GLfloat shininess_floor = 50;
   */ 
    
    glPushMatrix();
        glColor3f(0,1,0);
//         glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_floor);
//         glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_floor);
//         glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_floor);
//         glMaterialf(GL_FRONT, GL_SHININESS, shininess_floor);

        glScalef(100,4,2);
        glTranslatef(0,-1.66,0);
        glutSolidCube(1);
    glPopMatrix();
    
//     GLfloat ambient_coeffs_player[] = { 0, 0.3, 0.7, 1 };
//     GLfloat diffuse_coeffs_player[] = { 0.0, 0.0, 0.8, 1 };
//     GLfloat specular_coeffs_player[] = { 1, 1, 1, 1 };
//     GLfloat shininess_player = 50;
 
    glPushMatrix();
        glColor3f(0, 0.3,0.7);
        
    /*    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_player);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_player);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_player);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess_player);
        //glDisable(GL_LIGHTING);
    */   
    glPushMatrix();
        glTranslatef(player_posX, player_posY, 0);
        glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
    
    glPushMatrix();
        //printf("%d  ", coll);
        if(coll){
            output(0,0, "SUDAR");
        }
        glColor3f(1,0,0);
        glTranslatef(translate_level,0,0);
        draw_lvl();
    glPopMatrix();
  
    output(12.5,8.5, "Score: ");
    glutPostRedisplay();
    glutSwapBuffers();
}
