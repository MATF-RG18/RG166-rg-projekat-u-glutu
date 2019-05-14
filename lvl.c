#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>


//static int window_width, window_height;


// static void on_keyboard(unsigned char key, int x, int y);
// static void on_reshape(int width, int height);
// static void on_display(void);

 void draw_small_terrain(float, float, float );
 void draw_medium_terrain(float, float, float );
 void draw_big_terrain(float, float, float );
 void draw_obstacle(float, float, float );
 void draw_lvl();


/*int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);


    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    /* Registruju se callback funkcije. */

    /*glutKeyboardFunc(on_keyboard);
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);

    /* Obavlja se OpenGL inicijalizacija. */
   /* glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glLineWidth(2);
    
    /* Program ulazi u glavnu petlju. */
   /* glutMainLoop();

    return 0;
}

static void on_keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        /* Zavrsava se program. */
   /*     exit(0);
        break;
    case 'd':
    case 'D':
        animation += 2;
        break;
    }
}

static void on_reshape(int width, int height)
{
    /* Pamte se sirina i visina prozora. */
  /*  window_width = width;
    window_height = height;
}


static void on_display(void)
{
    
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
            0, 0, 20,
            0, 0, 0,
            0, 1, 0 
        );
    glColor3f(1,1,0);
    
    glPushMatrix();
        glTranslatef(-10.0,0,0);
        draw_medium_terrain(0,-3,0);
        draw_big_terrain(1,-3,0);
        draw_medium_terrain(4,-2,0);
        draw_small_terrain(2,-2,0);
        draw_small_terrain(3.5,-1,0);
        draw_small_terrain(5,0,0);
        draw_obstacle(8,-4,0);
        draw_obstacle(9,-4,0);
        draw_big_terrain(14,-4,0);
        //draw_medium_terrain(16, -4, 0);
        draw_obstacle(18,-4,0);
        draw_obstacle(19,-4,0);
        draw_big_terrain(20,-4,0);
        
        
    glPopMatrix();
    
    
    glBegin(GL_LINES);
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(10,0,0);
    glEnd();
    
    glBegin(GL_LINES);
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,10,0);
    glEnd();
    
    glBegin(GL_LINES);
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,10);
    glEnd();
        
    glutSwapBuffers();
}*/

void draw_lvl(){
    glPushMatrix();
        //glTranslatef(-10.0,0,0);
        draw_medium_terrain(0,-3,0);
        draw_big_terrain(1,-3,0);
        draw_medium_terrain(4,-2,0);
        draw_small_terrain(2,-2,0);
        draw_small_terrain(3.5,-1,0);
        draw_small_terrain(5,0,0);
        draw_obstacle(8,-4,0);
        draw_obstacle(9,-4,0);
        draw_big_terrain(14,-4,0);
        //draw_medium_terrain(16, -4, 0);
        draw_obstacle(18,-4,0);
        draw_obstacle(19,-4,0);
        draw_big_terrain(20,-4,0);
        
        
    glPopMatrix();
}

void draw_small_terrain(float position_x, float position_y, float position_z){
    glPushMatrix();
        glScalef(1, 0.5, 0.1);
        glTranslatef(position_x,position_y,position_z);
        glutSolidCube(1);
    glPopMatrix();
}

void draw_medium_terrain(float position_x, float position_y, float position_z){
    glPushMatrix();
        glScalef(3,1,0.1);
        glTranslatef(position_x,position_y,position_z);
        glutSolidCube(1);
    glPopMatrix();
}

void draw_big_terrain(float position_x, float position_y, float position_z){
    glPushMatrix();
        glScalef(5,2,0.1);
        glTranslatef(position_x,position_y,position_z);
        glutSolidCube(1);
    glPopMatrix();
}

void draw_obstacle(float position_x, float position_y, float position_z){
    glPushMatrix();
        glTranslatef(position_x,position_y,position_z);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.4,0.7,10,1);
    glPopMatrix();
}
