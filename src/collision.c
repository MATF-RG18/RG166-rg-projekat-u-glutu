#include "variables.h"

static void free_fall(){
    if((player_posY >= posMin) && free_fall_active)
        player_posY -= 0.025;
    if(player_posY <= posMin && free_fall_active){
        player_posY = posMin;
        jump_count = true;
        free_fall_active = false;
        return;
    }
    
    glutPostRedisplay();
	glutTimerFunc(1000/60, free_fall, 0);
}

bool collision_small_terrain(float posX, float posY, float terrain_with, float terrain_height){
    if(posX + terrain_with < player_posX - player_width)
        return false;
    if(posX - terrain_with > player_posX + player_width)
        return false;
    if(posY + terrain_height < player_posY - player_height)
        return false;
    if(posY - to_ground > player_posY + player_height)
        return false;
    
    if((abs(posX + terrain_with + player_width - player_posX) >= 0.0) && (abs(posX + terrain_with + player_width - player_posX) <= 0.4)){
        can_jump = true;
    } else 
        can_jump = false;
   
    if((posY + terrain_height + player_height - player_posY < 0.175) && (posX + terrain_with >= player_posX)){
        posMin = posY + 0.75;
        posMax = posY + 3.75;
        return false;
    }
    
    if((posX + terrain_with + player_width - player_posX >= 0) && (posX + terrain_with + player_width - player_posX <= 0.5)){
        posMin = -4.0;
        posMax = -1.0;
        jump_count = false;
        free_fall_active = true;
        glutTimerFunc(0, free_fall, 0);
        return false;
    }
    
    free_fall_active = false;
    return true;
}

bool collision_medium_terrain(float posX, float posY, float terrain_with, float terrain_height){
    if(posX + terrain_with < player_posX - player_width)
        return false;
    if(posX - terrain_with > player_posX + player_width)
        return false;
    if(posY + terrain_height < player_posY - player_height)
        return false;
    if(posY - to_ground > player_posY + player_height)
        return false;
    
    if((abs(posX + terrain_with + player_width - player_posX) >= 0.0) && (abs(posX + terrain_with + player_width - player_posX) <= 2.90)){
        can_jump = true;
    } else 
        can_jump = false;
    if((posY + terrain_height + player_height - player_posY < 0.15) && (posX + terrain_with >= player_posX)){
        posMin = posY + 1.0;
        posMax = posY + 4.0;
        return false;
    }
    if((posX + terrain_with + player_width - player_posX >= 0) && (posX + terrain_with + player_width - player_posX <= 0.5)){
        posMin = -4.0;
        posMax = -1.0;
        jump_count = false;
        free_fall_active = true;
        glutTimerFunc(0, free_fall, 0);
        return false;
    }
    
    free_fall_active = false;
    return true;
}

bool collision_big_terrain(float posX, float posY, float terrain_with, float terrain_height){
    if(posX + terrain_with < player_posX - player_width)
        return false;
    if(posX - terrain_with > player_posX + player_width)
        return false;
    if(posY + terrain_height < player_posY - player_height)
        return false;
    if(posY - to_ground > player_posY + player_height)
        return false;
    
    if((abs(posX + terrain_with + player_width - player_posX) >= 0.0) && (abs(posX + terrain_with + player_width - player_posX) <= 2.90)){
        can_jump = true;
    } else 
        can_jump = false;
    if((posY + terrain_height + player_height - player_posY < 0.15) && (posX + terrain_with >= player_posX)){
        posMin = posY + 1.5;
        posMax = posY + 4.5;
        return false;
    }
    
    if(free_fall_active)
        glutTimerFunc(0, free_fall, 0);
    
    if((posX + terrain_with + player_width - player_posX >= 0) && (posX + terrain_with + player_width - player_posX <= 0.175)){
        posMin = -4.0;
        posMax = -1.0;
        jump_count = false;
        free_fall_active = true;
        glutTimerFunc(0, free_fall, 0);
        return false;
    }
    free_fall_active = false;
    return true;
}

bool collision_obstacle(float posX, float posY, float terrain_with, float terrain_height){
    if(posX + terrain_with < player_posX - player_width)
        return false;
    if(posX - terrain_with > player_posX + player_width)
        return false;
    if(posY + terrain_height < player_posY - player_height)
        return false;
    if(posY - terrain_height > player_posY + player_height)
        return false;
    
    return true;
}

bool collision_coin(float posX, float posY, float coin_width, float coin_height){
    if(posX + coin_width < player_posX - player_width)
        return false;
    if(posX - coin_width > player_posX + player_width)
        return false;
    if(posY + coin_height < player_posY - player_height)
        return false;
    if(posY - coin_height > player_posY + player_height)
        return false;
    
    return true;
}
