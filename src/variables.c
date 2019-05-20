# include "variables.h"

float player_posY = -4.0;
float player_posX = -6.0;
float posMax = -1.0;
float posMin = -4.0;
float translate_level = 10;
float translate_coef = 0.075;
float fall_speed = 0.175;
float jump_speed = 0.15;
float player_width = 0.5;
float player_height = 0.5;
float to_ground = 10;

bool jump_count = true;
bool coll;
bool free_fall_active;
bool in_jump;
bool can_jump;
