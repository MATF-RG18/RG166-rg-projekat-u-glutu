#include "variables.h"

void set_light(){
    GLfloat position [] = {5,10,10,1};
	GLfloat ambient  [] = {0.4,0.4,0.4,1};
	GLfloat diffuse  [] = {1.0,1.0,1.0,1};
	GLfloat specular [] = {1,1,1,1};

	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    
}

void ground_light(){
    GLfloat ambient_coeffs_ground[] = { 0.0, 1.0, 0.0, 1 };
    GLfloat diffuse_coeffs_ground[] = { 0.0, 1.0, 0.0, 1 };
    GLfloat specular_coeffs_ground[] = { 0.0, 1.0, 0.0, 1 };
    int shininess_ground = 60;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_ground);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_ground);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_ground);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess_ground);
}

void terrain_light(){
    GLfloat ambient_coeffs_terrain[] = { 0.52, 0.24, 0.08, 1 };
    GLfloat diffuse_coeffs_terrain[] = { 0.52, 0.24, 0.08, 1 };
    GLfloat specular_coeffs_terrain[] = { 0.52, 0.24, 0.08, 1 };
    int shininess_terrain = 60;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_terrain);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_terrain);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_terrain);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess_terrain);
}

void player_light(){
    GLfloat ambient_coeffs_player[] = { 0.0, 0.3, 0.7, 1 };
    GLfloat diffuse_coeffs_player[] = { 0.0, 0.3, 0.7, 1 };
    GLfloat specular_coeffs_player[] = { 1.0, 1.0, 1.0, 1 };
    int shininess_player = 60;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_player);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_player);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_player);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess_player);
       
}

void coin_light(){
    GLfloat ambient_coeffs_coin[] = { 1, 1, 0, 1 };
    GLfloat diffuse_coeffs_coin[] = { 1, 1, 0, 1 };
    GLfloat specular_coeffs_coin[] = { 1, 1, 0, 1 };
    int shininess_coin = 60;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_coin);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_coin);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_coin);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess_coin);
    
}

void obstacle_light(){
    GLfloat ambient_coeffs_obstacle[] = { 0.0, 0.4, 0.0, 1 };
    GLfloat diffuse_coeffs_obstacle[] = { 0.0, 0.4, 0.0, 1 };
    GLfloat specular_coeffs_obstacle[] = { 0.0, 0.4, 0.0, 1 };
    int shininess_obstacle = 6;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_obstacle);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_obstacle);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_obstacle);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess_obstacle);
    
}

void white_light(){
    GLfloat ambient_coeffs_white[] = { 1.0, 1.0, 1.0, 1 };
    GLfloat diffuse_coeffs_white[] = { 1.0, 1.0, 1.0, 1 };
    GLfloat specular_coeffs_white[] = { 1.0, 1.0, 1.0, 1 };
    int shininess_white = 6;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_white);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_white);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_white);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess_white);
    
}
void black_light(){
    GLfloat ambient_coeffs_black[] = { 0.0, 0.0, 0.0, 1 };
    GLfloat diffuse_coeffs_black[] = { 0.0, 0.0, 0.0, 1 };
    GLfloat specular_coeffs_black[] = { 0.0, 0.0, 0.0, 1 };
    int shininess_black = 6;
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_coeffs_black);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_coeffs_black);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_coeffs_black);
    glMaterialf(GL_FRONT, GL_SHININESS, shininess_black);
    
}

