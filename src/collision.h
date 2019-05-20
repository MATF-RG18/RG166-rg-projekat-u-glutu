#ifndef COLLISION_H
#define COLLISION_H


static void free_fall();

bool collision_small_terrain(float posX, float posY, float terrain_width, float terrain_height);
bool collision_medium_terrain(float posX, float posY, float terrain_width, float terrain_height);
bool collision_big_terrain(float posX, float posY, float terrain_width, float terrain_height);
bool collision_obstacle(float posX, float posY, float terrain_width, float terrain_height);
bool collision_coin(float posX, float posY, float coin_width, float coin_height);


#endif
