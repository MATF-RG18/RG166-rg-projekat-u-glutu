#include "variables.h"

void draw_lvl(){
    glPushMatrix();
        //if(!coll)
        draw_coin(-2, -4, 0);
        draw_coin(0, -4, 0);
        draw_coin(2, -2, 0);
        draw_coin(4, -4, 0);
        /*
         draw_small_terrain(4.5,-3,0);
         draw_small_terrain(7,-2,0);
         draw_small_terrain(9.5,-1,0);
         draw_obstacle(12,-4.5,0);
         draw_obstacle(13,-4.5,0);
         draw_big_terrain(23,-4,0);
         draw_obstacle(29,-4.5,0);
         draw_obstacle(30,-4.5,0);
         draw_big_terrain(37,-2.0,0);
         draw_small_terrain(43, -1.5, 0);
         draw_small_terrain(45.5, -1.0, 0);
         draw_small_terrain(47, -0.5, 0);
         draw_small_terrain(49, -0.5, 0);
         draw_small_terrain(51, -0.5, 0);
         draw_small_terrain(53, -0.5, 0);
         */
    glPopMatrix();
   
}

void draw_small_terrain(float position_x, float position_y, float position_z){
    glPushMatrix();
        glTranslatef(position_x,position_y,position_z);
        glScalef(1.5, 0.5, 1);
        glutSolidCube(1);
    glPopMatrix();
    
    float real_positionX = position_x + translate_level;
    if(collision_small_terrain(real_positionX, position_y, 0.75, 0.25))
        coll = true;
    else if ((real_positionX <= player_posX - 1.25) && !(collision_small_terrain(real_positionX, position_y, 0.75, 0.25)))
        coll = false;
}

void draw_medium_terrain(float position_x, float position_y, float position_z){
    glPushMatrix();
        glTranslatef(position_x,position_y,position_z);
        glScalef(5,1,1);
        glutSolidCube(1);
    glPopMatrix();
    
    float real_positionX = position_x + translate_level; //Trenutna pozicija objekta
    if(collision_medium_terrain(real_positionX, position_y, 2.5, 0.5))
        coll = true;
    else if((real_positionX <= player_posX - 3.0) && !(collision_medium_terrain(real_positionX, position_y, 2.5, 0.5)))
        coll = false;
}

void draw_big_terrain(float position_x, float position_y, float position_z){
    glPushMatrix();
        glTranslatef(position_x,position_y,position_z);
        glScalef(10,2,1);
        glutSolidCube(1);
    glPopMatrix();
    
    float real_positionX = position_x + translate_level;
    if(collision_big_terrain(real_positionX, position_y, 5.0, 1.0))
        coll = true;
    else if((real_positionX <= player_posX - 5.5) && !(collision_big_terrain(real_positionX, position_y, 5.0, 1.0)))
        coll = false;
}

void draw_obstacle(float position_x, float position_y, float position_z){
    glPushMatrix();
        glTranslatef(position_x,position_y,position_z);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.4,0.7,10,1);
    glPopMatrix();
    
    float real_positionX = position_x + translate_level;
    if(collision_obstacle(real_positionX, position_y, 0.2, 0.35))
        coll = true;
    else if ((real_positionX <= player_posX - 0.7) && !(collision_obstacle(real_positionX, position_y, 0.2, 0.35)))
        coll = false;
}

void draw_coin(float position_x, float position_y, float position_z){
    float real_positionX = position_x + translate_level;
    
    if(collision_coin(real_positionX, position_y, 0.25, 0.25))
        return;
    if((real_positionX <= player_posX - 0.75))
        return;
    glPushMatrix();
        glTranslatef(position_x, position_y, position_z);
        glScalef(0.5,0.5,0.1);
        glutSolidSphere(1, 10, 10);
    glPopMatrix();
}
