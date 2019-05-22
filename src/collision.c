#include "variables.h"

//Kolizija je implementirana koriscenjem AABB kolizije za 2d
//Iako je igrica u 3d-u sve se nalazi na istoj Y ravni 
//pa sam zato implementirao ovako

bool collision_small_terrain(float posX, float posY, float terrain_with, float terrain_height){
    if(posX + terrain_with < player_posX - player_width)
        return false;
    if(posX - terrain_with > player_posX + player_width)
        return false;
    if(posY + terrain_height < player_posY - player_height)
        return false;
    if(posY - to_ground > player_posY + player_height)
        return false;
    
    //Proveravamo da li je igrac blizu do ivice
    if((abs(posX + terrain_with + player_width - player_posX) >= 0.0) && (abs(posX + terrain_with + player_width - player_posX) <= 1.0)){
        can_jump = true;
    } else 
        can_jump = false;
    
    //Ukoliko je igrac na ili iznad terena postavlja mu se max i min visina visina na odredjenje vrednosti
    if((posY + terrain_height + player_height - player_posY < 0.2) && (posX + terrain_with >= player_posX)){
        posMin = posY + 0.75;
        posMax = posY + 3.75;
        return false;
    }
    
    //Ukoliko je igrac prosao teren ukljucujemo slobodan pad
    if((posX + terrain_with + player_width - player_posX >= 0) && (posX + terrain_with + player_width - player_posX <= 0.5)){
        posMin = -4.0;
        posMax = -1.0;
        jump_count = false;
        free_fall_active = true;
       // glutTimerFunc(0, free_fall, 0);
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
    
    //Proveravamo da li je igrac blizu do ivice
    if((abs(posX + terrain_with + player_width - player_posX) >= 0.0) && (abs(posX + terrain_with + player_width - player_posX) <= 2.90)){
        can_jump = true;
    } else 
        can_jump = false;
    
    //Ukoliko je igrac na ili iznad terena postavlja mu se max i min visina visina na odredjenje vrednosti
    if((posY + terrain_height + player_height - player_posY < 0.2) && (posX + terrain_with >= player_posX)){
        posMin = posY + 1.0;
        posMax = posY + 4.0;
        return false;
    }
    
    //Ukoliko je igrac prosao teren ukljucujemo slobodan pad
    if((posX + terrain_with + player_width - player_posX >= 0) && (posX + terrain_with + player_width - player_posX <= 0.5)){
        posMin = -4.0;
        posMax = -1.0;
        jump_count = false;
        free_fall_active = true;
        //glutTimerFunc(0, free_fall, 0);
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
    
    //Proveravamo da li je igrac blizu do ivice
    if((abs(posX + terrain_with + player_width - player_posX) >= 0.0) && (abs(posX + terrain_with + player_width - player_posX) <= 3.0)){
        can_jump = true;
    } else 
        can_jump = false;
    
    //Ukoliko je igrac na ili iznad terena postavlja mu se max i min visina visina na odredjenje vrednosti
    if((posY + terrain_height + player_height - player_posY < 0.2) && (posX + terrain_with >= player_posX)){
        posMin = posY + 1.5;
        posMax = posY + 4.5;
        return false;
    }
    //Ukoliko je igrac prosao teren ukljucujemo slobodan pad
    if((posX + terrain_with + player_width - player_posX >= 0) && (posX + terrain_with + player_width - player_posX <= 0.2)){
        posMin = -4.0;
        posMax = -1.0;
        jump_count = false;
        free_fall_active = true;
        //glutTimerFunc(0, free_fall, 0);
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
