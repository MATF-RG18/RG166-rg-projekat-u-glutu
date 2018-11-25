#include <stdlib.h>
#include <GL/glut.h>

GLfloat jumpMax = 2.3f;
GLfloat jumpSpeed = 0.05f;
GLfloat posY = 4.0f;
GLfloat posZ = -6.0f;
GLfloat posMax = 3.0f;
GLfloat posMin = 4.0f;
GLfloat cone_posZ = 4.0f;
GLint jumpCount = 0;

static int window_width, window_height;


static void on_keyboard(unsigned char key, int x, int y);
static void on_reshape(int width, int height);
static void on_display(void);
static void jump(int);
static void cone_move(int);

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);


    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    /* Registruju se callback funkcije. */
    glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    /* Obavlja se OpenGL inicijalizacija. */
    glClearColor(0.75, 0.75, 0.75, 0);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);
    
    glutTimerFunc(25, cone_move, 0);
    /* Program ulazi u glavnu petlju. */
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
	glutTimerFunc(1,jump, jumpCount);
	/*if(posY >= posMax)
		posY = posY - 0.1;
	else
		posY = posY + 2.0;*/
	
	//glutPostRedisplay();
	break;
    }
}

static void on_reshape(int width, int height)
{
    /* Pamte se sirina i visina prozora. */
    window_width = width;
    window_height = height;
}

static void jump(int value){
	if(value == 1){
		jumpCount = 0;
	}
	else{
		posY -= 0.02f;
		if(posY <= posMax)
		posY = posMin;

		glutPostRedisplay();
		glutTimerFunc(25, jump, 0);
		jumpCount = 1;
	}
}

static void cone_move(int value){
	cone_posZ -= 0.1;
	glutPostRedisplay();
	glutTimerFunc(25,cone_move, 0);
}
static void on_display(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /* Podesava se viewport. */
    glViewport(0, 0, window_width, window_height);

    /* Podesava se projekcija. */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(
            60,
            window_width/(float)window_height,
            1, 25);

    /* Podesava se tacka pogleda. */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
            15, 1, 0,
            0, 0, 0,
            1, 0, 0
        );
    //igrac
    glColor3f(0, 0.3,0.7);
    glPushMatrix();
    glTranslatef(0,posY, posZ);
    glutSolidCube(1);
    glPopMatrix();
    
    //prepreka
    glColor3f(0,0,0);
    glPushMatrix();
    glTranslatef(0,0,cone_posZ);
    glRotatef(90,1,0,0);
    glutSolidCone(0.3,1,10,1);
    glPopMatrix();

    glutPostRedisplay();
    glutSwapBuffers();
}
