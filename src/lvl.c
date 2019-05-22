#include "variables.h"

void draw_lvl(){
    //Rucno napravljen nivo
    glPushMatrix();
        draw_obstacle(2, -4.5, 0);
        draw_coin(4.5,-4.0,0,0);
        draw_obstacle(7,-4.5,0);
        draw_coin(9.5,-4.0,0,1);
        draw_obstacle(13,-4.5,0);
        draw_big_terrain(23,-4,0);
            draw_coin(19,-2.5,0,2);
            draw_coin(23,-2.5,0,3);
            draw_coin(27,-2.5,0,4);
        draw_obstacle(29,-4.5,0);
        draw_obstacle(30,-4.5,0);
        draw_big_terrain(36,-4,0);
        draw_obstacle(36,-3,0);
        draw_coin(36,-1.0,0,5);
        draw_small_terrain(42, -2,0);
        draw_small_terrain(45.5, -1,0);
        draw_small_terrain(49, 0,0);
        draw_coin(53,1.5,0,6);
        draw_obstacle(55,-4.5,0);
        draw_medium_terrain(65.5, -3,0);
            draw_obstacle(63.5,-4.5,0);
            draw_obstacle(64.5,-4.5,0);
            draw_obstacle(65.5,-4.5,0);
            draw_obstacle(66.5,-4.5,0);
        draw_small_terrain(70,-2,0);
        draw_small_terrain(73.5,-1,0);
        draw_small_terrain(77,0,0);
        draw_small_terrain(80.5,1,0);
        draw_small_terrain(84,2,0);
        draw_small_terrain(87.5,3,0);
        draw_medium_terrain(93,1,0);
            draw_coin(93,2,0,7);
        draw_medium_terrain(101.5,-1,0);
        draw_medium_terrain(110.5,-3,0);
            draw_coin(110.5,-2,0, 8);
        
        draw_obstacle(120,-4.5,0);
        draw_obstacle(121,-4.5,0);
        
        draw_coin(125,-4.0,0,9);
        draw_obstacle(129,-4.5,0);
        
        draw_big_terrain(140,-4,0);
            draw_coin(136,-2.5,0,10);
            draw_coin(140,-2.5,0,11);
            draw_coin(144,-2.5,0,12);
        draw_obstacle(146,-4.5,0);
        draw_obstacle(147,-4.5,0);
        draw_big_terrain(153,-4,0);
        
        draw_obstacle(165,-4.5,0);
        draw_small_terrain(172, -3,0);
        draw_small_terrain(175,-2,0);
        draw_big_terrain(182, -3, 0);
            draw_coin(178, -1.5, 0,13);
            draw_obstacle(182,-2.0,0);
        draw_big_terrain(194, -3, 0);
            draw_obstacle(194,-2.,0);
            draw_coin(197,-1.5,0, 14);
        draw_finish_pole(210, -4,0);
    glPopMatrix();
   
}

void draw_finish_pole(float position_x, float position_y, float position_z){
    glPushMatrix();
        glTranslatef(position_x,position_y,position_z);
        glPushMatrix();
            glScalef(0.2,1,0.1);
            white_light();
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0,1,0);
            glScalef(0.2,1,0.1);
            black_light();
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0,2,0);
            glScalef(0.2,1,0.1);
            white_light();
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0,3,0);
            glScalef(0.2,1,0.1);
            black_light();
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.2,3,0);
            glScalef(0.2,1,0.1);
            white_light();
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.4,3,0);
            glScalef(0.2,1,0.1);
            black_light();
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.6,3,0);
            glScalef(0.2,1,0.1);
            white_light();
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.8,3,0);
            glScalef(0.2,1,0.1);
            black_light();
            glutSolidCube(1);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(1.0,3,0);
            glScalef(0.2,1,0.1);
            white_light();
            glutSolidCube(1);
        glPopMatrix();
    glPopMatrix();
    
    float real_positionX = position_x + translate_level;
    if(player_posX >= real_positionX + 1){
        endgame = true;
    }
}

//Iscrtavanje malog pravougaonika
void draw_small_terrain(float position_x, float position_y, float position_z){
    //Postavljamo objekat na zeljenu poziciju
    glPushMatrix();
        glTranslatef(position_x,position_y,position_z);
        glScalef(1.5, 0.5, 1);
        terrain_light();
        glutSolidCube(1);
    glPopMatrix();
    
    //Trazimo trenutnu poziciju
    float real_positionX = position_x + translate_level;
    
    //Proveravamo da li je igrac udario u objekat
    if(collision_small_terrain(real_positionX, position_y, 0.75, 0.25))
        coll = true;
    //Ako collision ne vraca True i ako ce objekat nalazi levo od igraca vise da ne detektujemo 
    else if ((real_positionX <= player_posX - 1.25) && !(collision_small_terrain(real_positionX, position_y, 0.75, 0.25)))
        coll = false;
}


//Iscrtavanje srednjeg pravougaonika
void draw_medium_terrain(float position_x, float position_y, float position_z){
    //Postavljamo objekat na zeljenu poziciju
    glPushMatrix();
        glTranslatef(position_x,position_y,position_z);
        glScalef(5,1,1);
        terrain_light();
        glutSolidCube(1);
    glPopMatrix();
    
    //Trazimo trenutnu poziciju objekta
    float real_positionX = position_x + translate_level;
    if(collision_medium_terrain(real_positionX, position_y, 2.5, 0.5))
        coll = true;
    //Ako je objekat sa leve strane igraca ne detektujemo ga(isto kao gore samo druge koordinate)
    else if((real_positionX <= player_posX - 3.0) && !(collision_medium_terrain(real_positionX, position_y, 2.5, 0.5)))
        coll = false;
}

//Iscrtavanje velikog pravougaonika
void draw_big_terrain(float position_x, float position_y, float position_z){
    //Postavljamo objetak na zeljenu poziciju
    glPushMatrix();
        glTranslatef(position_x,position_y,position_z);
        glScalef(10,2,1);
        terrain_light();
        glutSolidCube(1);
    glPopMatrix();
    
    //Trazimo trenutnu poziciju objekta
    float real_positionX = position_x + translate_level;
    if(collision_big_terrain(real_positionX, position_y, 5.0, 1.0))
        coll = true;
    //Ako je objekat sa leve strane igraca ne detektujemo ga
    else if((real_positionX <= player_posX - 5.5) && !(collision_big_terrain(real_positionX, position_y, 5.0, 1.0)))
        coll = false;
}

//Iscrtavanja prepreke
void draw_obstacle(float position_x, float position_y, float position_z){
    //Postavljamo na zeljenu poziciju i rotiramo jer je objekat oboren nadesno u pocetnoj poziciju 
    glPushMatrix();
        glTranslatef(position_x,position_y,position_z);
        glRotatef(-90,1,0,0);
        obstacle_light();
        glutSolidCone(0.4,0.7,10,1);
    glPopMatrix();
    
    //Trazimo trenutnu poziciju objekta
    float real_positionX = position_x + translate_level;
    if(collision_obstacle(real_positionX, position_y, 0.2, 0.35))
        coll = true;
    //Ako je objekat za leve strane igraca ne detektujemo ga
    else if ((real_positionX <= player_posX - 0.7) && !(collision_obstacle(real_positionX, position_y, 0.2, 0.35)))
        coll = false;
}

void draw_coin(float position_x, float position_y, float position_z, int coin_number){
    //Trenutna pozicija novcica
    float real_positionX = position_x + translate_level;
    
    //Ako igrac udari levu stranu novcica dobija 50 poena i brojac se stavlja na True
    if(collision_coin(real_positionX, position_y, coin_width, coin_width) && 
        (real_positionX - player_posX + coin_width >= 0) && 
        (real_positionX - player_posX + coin_width <= translate_coef)){
                                        
        score += 50;
        coin_coll[coin_number] = true;
    }
    
    //Ako igraci udari desnu stranu novcica (pri padu iz skoka) dobija 50 boda i brojac se stavlja na True
    if(!coin_coll[coin_number] && collision_coin(real_positionX, position_y, coin_width, coin_width) &&
        (real_positionX - player_posX + player_width + coin_width >= 0) && 
        (real_positionX - player_posX + player_width + coin_width <= translate_coef)){
        
        score += 50;
        coin_coll[coin_number] = true;
    }
    
    //Ukoliko je brojac True za trenutni novcic onda se ona ne ispisuje
    if(coin_coll[coin_number])
        return;
    //Postavljamo novcic na zeljenoj poziciji
    glPushMatrix();
        glTranslatef(position_x, position_y, position_z);
        glScalef(0.5,0.5,0.1);
        coin_light();
        glutSolidSphere(1, 10, 10);
    glPopMatrix();
}
