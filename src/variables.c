# include "variables.h"

int score = 0;

//Pocetne pozicije X i Y  igraca
float player_posY = -4.0;
float player_posX = -6.0;

//Najveca visina koju moze dostici igrac pri skoku
float posMax = -1.0;
//Najmanja visina koju moze dostici igrac pri padu
float posMin = -4.0;

//Pocetak translacije za nivo(tj pocetna pozicija nivoa)
float translate_level = 10;
//Brzina pomeranja nivoa ka igracu;
float translate_coef = 0.1;

//Brzina pada igraca
float fall_speed = 0.2;
//Brzina skoka igraca
float jump_speed = 0.175;

//Sirina i duzina igraca
float player_width = 0.5;
float player_height = 0.5;

//Sirina novcica
float coin_width = 0.25;

//Visina od prepreke do zemlje
float to_ground = 10;

//Skor dobijen tokom vremena
float score_translate_add = 0;

//Cuva podatak o tome da li je igrac u skoku
bool jump_count = true;

//Detekcija kolizije
bool coll;

//Detektuje da li igrac u slobodnom padu
bool free_fall_active;
bool in_jump;

//Detektuje da li igrac moze da skoci sa ivice terena
bool can_jump;

//Niz koji cuva kolizije za sve nocice
bool coin_coll[COIN_COUNT];

//Detektuje kraj igre
bool endgame; 

bool w_pressed;
