#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <GL/glut.h>
#include "lvl.h"

GLfloat jumpMax = 2.3f;
GLfloat jumpSpeed = 0.05f;
GLfloat player_posY = -4.0f;
GLfloat player_posX = -6.0f;
GLfloat posMax = -2.0f;
GLfloat posMin = -4.0f;
GLfloat cone_posX = 9.0f;
GLfloat cone_posY = 0.0f;
GLint jump_count = 1;
GLfloat test_kol = 0;
int cone_display = 1;

static int window_width, window_height;


static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void jump(int);
static void cone_move(int);
static void make_cone(int);
static int random_position(int);
static void test_kolizije();
bool collision(float, float);
void output(int x, int y, char* string);

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);


    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    /* Registruju se callback funkcije. */
    cone_posY = random_position(16);

    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);
    
    glutTimerFunc(1000/60, cone_move, 0);
    glutTimerFunc(1000/60, test_kolizije, 0);
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
    case 'w':
	if(jump_count == 1 && player_posY == posMin)
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
  glColor3f( 0, 1.0, 1.0 );
  glRasterPos2f(x, y);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
  }
}
 
static void test_kolizije(){
    test_kol -= 0.1;
    if(!(collision(test_kol, -4.0)))
        output(100,150, "Sudar!");
    glutPostRedisplay();
    glutTimerFunc(1000/60, test_kolizije, 0);
    
}

bool collision(float posX, float posY){
    if(posX + 0.5 < player_posX)
        return false;
    if(posX > player_posX + 0.5)
        return false;
    
    if(posY + 0.5 < player_posY)
        return false;
    if(posY > player_posY + 0.5)
        return false;
    
    return true;
}

static void jump(int value){
	
	if(player_posY <= posMax && jump_count == 1){
		player_posY += 0.1f;
	}
	else if(player_posY >= posMax){
		jump_count = 0;
	}
	
	if(player_posY >= posMin && jump_count == 0)
		player_posY -= 0.1f ;
	else if(player_posY <= posMin){
		player_posY = posMin;
		jump_count = 1;
		return;
	}

	glutPostRedisplay();
	glutTimerFunc(1000/60, jump, 0);
}

static void cone_move(int value){
	if(cone_posX >= -10.0){
		cone_posX -= 0.1;
		glutPostRedisplay();
		glutTimerFunc(1000/60,cone_move, 0);
		cone_display = 1;
	}
	else
		cone_display = 0;
}

static int random_position(int value){
	srand(time(NULL));
	if(rand()%value - 8 < player_posY)
		return player_posY;
	else
		return rand()%value - 8;
}

static void make_cone(int num_of_cones){
	
	for(int i=0; i<=num_of_cones; i++){
    	   if(cone_display){
       	      glColor3f(0,1,0);
              glPushMatrix();
              glTranslatef(cone_posX, cone_posY,0);
              glRotatef(-90,1,0,0);
              glutSolidCone(0.3,1,10,1);
	      glPopMatrix();
	    }
	}

}

static void on_display(void)
{
    
    GLfloat light_position[] = {1,1,1,0};
    GLfloat light_ambient[] = {0.0,0.0,0.0,1};
    GLfloat light_diffuse[] = {0.7,0.7,0.7,1};
    GLfloat light_specular[] = {0.9,0.9,0.9,1};
    
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
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    
    GLfloat ambient_coeffs_floor[] = { 0, 0, 1, 1 };
    GLfloat diffuse_coeffs_floor[] = { 0.0, 0.0, 0.8, 1 };
    GLfloat specular_coeffs_floor[] = { 1, 1, 1, 1 };
    GLfloat shininess_floor = 50;
    
    
    glPushMatrix();
        glColor3f(0,0,1);
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_floor);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_floor);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_floor);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess_floor);

        glScalef(20,4,1);
        glTranslatef(0,-1.66,0);
        glutSolidCube(1);
        //glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'c');
    glPopMatrix();
    //igrac
    
    output(150,100, "TEST");
    //glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'c');
    GLfloat ambient_coeffs_player[] = { 0, 0.3, 0.7, 1 };
    GLfloat diffuse_coeffs_player[] = { 0.0, 0.0, 0.8, 1 };
    GLfloat specular_coeffs_player[] = { 1, 1, 1, 1 };
    GLfloat shininess_player = 50;

    if(collision(test_kol, -4.0))
        output(0,0, "Sudar!");
    
    glPushMatrix();
        glColor3f(0, 0.3,0.7);
        
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_player);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_player);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_player);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess_player);
        //glDisable(GL_LIGHTING);
        glPushMatrix();
        glTranslatef(player_posX, player_posY, 0);
        glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
    
    draw_lvl();

    glPushMatrix();
        make_cone(10);
    glPopMatrix();
    
    glPushMatrix();
        glTranslatef(test_kol,-4.0,0);
        glutSolidCube(1);
    glPopMatrix();
  
    
    glutPostRedisplay();
    glutSwapBuffers();
}
