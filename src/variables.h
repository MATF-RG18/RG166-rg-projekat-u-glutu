#ifndef VARIABLES_H
#define VARIABLES_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#include "lvl.h"
#include "collision.h"
#include "light.h"

#define COIN_COUNT 20
#define SCORE_SIZE 55

extern int score;

extern float player_posY;
extern float player_posX;
extern float posMax;
extern float posMin;
extern float translate_level;
extern float translate_coef;
extern float jump_speed;
extern float fall_speed;
extern float player_width;
extern float player_height;
extern float to_ground;
extern float coin_width;
extern float score_translate_add;

extern bool jump_count;
extern bool coll;
extern bool free_fall_active;
extern bool in_jump;
extern bool can_jump;
extern bool coin_coll[COIN_COUNT];
extern bool endgame;
extern bool w_pressed;

#endif
