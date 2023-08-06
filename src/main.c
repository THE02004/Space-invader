#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "raylib.h" 
#include "raymath.h"
#include "Space.h"

int main(){
int mort = 0;
int vie = 0;
int wid = 1000;
int hei = 1920;
int f = 0;
int Score = 0;
int win = 0;
int waiste = 0;
int Af = 150;
bool gameover = false;
Vector2 victor = {0,0};
Vector2 Vintro = {0,-400};
Vector2 Vintro2 = {0,0};
Vector2 realpose = {1848,7};
Vector2 ast = {1000,-5000};
Vector2 monst = {1350,-5000};
Vector2 PMiss = {10,6000};
Vector2 PMiss2 = {10,6000};
Vector2 PMiss3 = {10,6000};
Vector2 PMiss4 = {10,6000};
Vector2 Pex = {2000,-30300};
Vector2 Pex1 = {2000,-30300};
Vector2 Pex2 = {2000,-30300};
Vector2 Pex3 = {2000,-30300};
Rectangle screen = {0,0,hei,wid};
Rectangle screen2 = {0,0,4000,2000};
Rectangle screen3 = {0,0,5000,2000};
Rectangle Rshep = {0,0,460,600};
Rectangle Rasteroid = {0,0,2000,1900};
Rectangle Rmonst = {0,55,177,90};
Rectangle DMiss = {0,140,50,190};
Rectangle Dex0 = {0,0,300,330};
Rectangle Dex1 = {300,0,300,330};
Rectangle Dex2 = {600,0,300,330};
Rectangle Dex3 = {900,0,300,330};
    // meteorite position
    int M = 0;
    //circle dimensions
    int circle_x = 2050;
    int circle_y = -3950;
    int circle_radius = 740;
        //edges of circle
    int l_circle = circle_x - circle_radius;
    int r_circle = circle_x + circle_radius;
    int u_circle = circle_y - circle_radius;
    int b_circle = circle_y + circle_radius;
   //
    // player
    int pole_x = 2030;
    int pole_y = 30;
    int pole_height = 500;
    int pole_width = 120;
        //edges of rectangle
    int l_pole = pole_x;
    int r_pole = pole_x + pole_width;
    int u_pole = pole_y;
    int b_pole = pole_y + pole_height;
    //aile
    int pole8_x = 1850;
    int pole8_y = 200;
    int pole8_height = 200;
    int pole8_width = 500;
        //edges of rectangle
    int l_pole8 = pole8_x;
    int r_pole8 = pole8_x + pole8_width;
    int u_pole8 = pole8_y;
    int b_pole8 = pole8_y + pole8_height;
    //=======================================
    // Game limit 
    int pole2_x = -1500;
    int pole2_y = -2850;
    int pole2_height = 3490;
    int pole2_width = 7000;
    //edge
    int l_pole2 = pole2_x;
    int r_pole2 = pole2_x + pole2_width;
    int u_pole2 = pole2_y;
    int b_pole2 = pole2_y + pole2_height;
    //=======================================================================================
    //Mob Hitbox
    int pole3_x = 1380;
    int pole3_y = -5000;
    int pole3_height = 70;
    int pole3_width = 130;
    //edge
    int l_pole3 = pole3_x;
    int r_pole3 = pole3_x + pole3_width;
    int u_pole3 = pole3_y;
    int b_pole3 = pole3_y + pole3_height;
    //======================================================================================
    //missile hitbox
    int pole4_x = 10380;
    int pole4_y = -7000;
    int pole4_height = 40;
    int pole4_width = 7;
    //edge
    int l_pole4 = pole4_x;
    int r_pole4 = pole4_x + pole4_width;
    int u_pole4 = pole4_y;
    int b_pole4 = pole4_y + pole4_height;
    //missile 2
    int pole5_x = 15380;
    int pole5_y = -7000;
    int pole5_height = 40;
    int pole5_width = 6;
    //edge
    int l_pole5 = pole3_x;
    int r_pole5 = pole3_x + pole5_width;
    int u_pole5 = pole3_y;
    int b_pole5 = pole3_y + pole5_height;
       //missile 3
    int pole6_x = 10380;
    int pole6_y = -7000;
    int pole6_height = 40;
    int pole6_width = 6;
    //edge
    int l_pole6 = pole6_x;
    int r_pole6 = pole6_x + pole6_width;
    int u_pole6 = pole6_y;
    int b_pole6 = pole6_y + pole6_height;
       //missile 4
  
    int pole7_x = 10380;
    int pole7_y = -7000;
    int pole7_height = 40;
    int pole7_width = 6;
    //edge
    int l_pole7 = pole7_x;
    int r_pole7 = pole7_x + pole7_width;
    int u_pole7 = pole7_y;
    int b_pole7 = pole7_y + pole7_height;
    //======================================================================================
    //Deaf
    bool collision = (l_circle < r_pole) && (r_circle > l_pole) && (u_circle < b_pole) && (b_circle > u_pole);
    bool collision2 = (l_circle < r_pole8) && (r_circle > l_pole8) && (u_circle < b_pole8) && (b_circle > u_pole8);
    bool Outofmap = (l_pole2 < r_pole) && (r_pole2 > l_pole) && (u_pole2 < b_pole) && (b_pole2 > u_pole);
    bool mobhitbox = (l_pole3 < r_pole) && (r_pole3 > l_pole) && (u_pole3 < b_pole) && (b_pole3 > u_pole);
    bool Missile1 = (l_pole3 < r_pole4) && (r_pole3 > l_pole4) && (u_pole3 < b_pole4) && (b_pole3 > u_pole4);
    bool Missile2 = (l_pole3 < r_pole5) && (r_pole3 > l_pole5) && (u_pole3 < b_pole5) && (b_pole3 > u_pole5);
    bool Missile3 = (l_pole3 < r_pole6) && (r_pole3 > l_pole6) && (u_pole3 < b_pole6) && (b_pole3 > u_pole6);
    bool Missile4 = (l_pole3 < r_pole7) && (r_pole3 > l_pole7) && (u_pole3 < b_pole7) && (b_pole3 > u_pole7);
    bool MissileMeteorite1 = (l_circle < r_pole4) && (r_circle > l_pole4) && (u_circle < b_pole4) && (b_circle > u_pole4);
    bool MissileMeteorite2 = (l_circle < r_pole5) && (r_circle > l_pole5) && (u_circle < b_pole5) && (b_circle > u_pole5);
    bool MissileMeteorite3 = (l_circle < r_pole6) && (r_circle > l_pole6) && (u_circle < b_pole6) && (b_circle > u_pole6);
    bool MissileMeteorite4 = (l_circle < r_pole7) && (r_circle > l_pole7) && (u_circle < b_pole7) && (b_circle > u_pole7);
    //
    // Vitess
    int V = 20;
    int VV = 15;
    int frameconter = 0;
    int intframe = 0;
    int frameconter2 = 0;
    int intframe2 = 0;
    //
  //attante
  int whait = 0;
  //
 InitWindow(hei, wid, "Space invader");
 InitAudioDevice();
  SetTargetFPS(60);
  const unsigned int CELL_SIZE = 1;
  const unsigned int GAME_WIDTH = GetScreenWidth() / CELL_SIZE;
  const unsigned int GAME_HEIGHT = GetScreenHeight() / CELL_SIZE;
  printf("%u, %u\n",GAME_WIDTH,GAME_HEIGHT);
  bool **tab;
  tab = tableaux(wid,hei);
  Image img = LoadImage("Space-Invaders-Ship.png");
  Texture2D img2d = LoadTexture("background.png"); 
  Texture2D playership = LoadTexture("Space-Invaders-Ship.png"); 
  Texture2D asteroid = LoadTexture("asteroid.png"); 
  Texture2D monster = LoadTexture("monster.png"); 
  Texture2D intro = LoadTexture("intro1.png"); 
  Texture2D intro2 = LoadTexture("intro2.png"); 
  Texture2D TMissile = LoadTexture("Space-Invaders-Ship.png"); 
  Texture2D TMissile2 = LoadTexture("Space-Invaders-Ship.png"); 
  Texture2D TMissile3 = LoadTexture("Space-Invaders-Ship.png"); 
  Texture2D TMissile4 = LoadTexture("Space-Invaders-Ship.png"); 
  Texture2D explosion = LoadTexture("explosion.png"); 
  Sound Sintro = LoadSound("intro.mp3");
  Sound Play = LoadSound("playSound.wav");
  Sound music = LoadSound("GTA.mp3");
  Sound Dead = LoadSound("Dead.mp3");
  Sound Shot = LoadSound("Shot.mp3");
  Sound Shot2 = LoadSound("Shot.mp3");
  Sound Shot3 = LoadSound("Shot.mp3");
  Sound Shot4 = LoadSound("Shot.mp3");
  Sound Sexplosion = LoadSound("Explosion.mp3");
  Sound Youwin = LoadSound("You Win.mp3");
  Sound SWin = LoadSound("Win.mp3");
  Sound Monsterdead = LoadSound("Monsterdead.mp3");
  SetSoundVolume(Sintro,0.2);  
  SetSoundVolume(Play,0.45);   
  SetSoundVolume(music,0.4);   
  SetSoundVolume(Dead,0.4);
  SetSoundVolume(Shot,0.4);
  SetSoundVolume(SWin,0.4);
  SetSoundVolume(Monsterdead,0.05);
  SetSoundVolume(Youwin,0.5);
  SetSoundVolume(Sexplosion,0.5);
  SetSoundPitch(Sexplosion,2.5);
  //---------------------------------------------------------
     Camera2D camera = { 0 };
    camera.target = (Vector2){500,500};
    camera.offset = (Vector2){ wid/2.0f, hei/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 0.29;
    //================
    int w = 0;
    int i = 0;
    while (!WindowShouldClose()){
    BeginDrawing();
    while(i<1){
    PlaySound(Sintro);
    ClearBackground(BLACK);
    i++;
    }
    while(w<1){
    if(IsKeyDown(KEY_SPACE)){
    PlaySound(Play);
    PlaySound(music);
    w++;
    }
    DrawTexturePro(intro2,screen3,screen3,Vintro2,0,WHITE);
    DrawTexturePro(intro,screen2,screen2,Vintro,0,WHITE);
    DrawText("-Welcome To Théo Space Invader-",120,200,90,DARKBLUE);
    DrawText("_Press Space To play_",500,700,70,BLUE);
    EndDrawing();
    }
    StopSound(Sintro);
    int del = 0;
    while(del = 0){
    UnloadTexture(intro);
    UnloadTexture(intro2);
    BeginDrawing();
    while(i = 1){
    StopSound(Play);
    i++;
    }
    del++;
    }
    ClearBackground(BLACK);
    DrawTexturePro(img2d,screen,screen,victor,0,WHITE);   
    BeginMode2D(camera);
    //DrawText("Score:",4500,-2800,Af,BLUE);
    Vector2 position =  GetMousePosition();
    DrawTextureRec(asteroid,Rasteroid,ast,WHITE);
    // Meteorite position
    if ((int)ast.y == 480 && M == 1){
    ast.x = 2000;
    ast.y = -5000;
    circle_y = -3950;
    circle_x = +3070;
    M = 2;
    V + 10;
    VV + 20;
    }
    if ((int)ast.y == 480 && M == 2){
    ast.x = 1000;
    ast.y = -5000;
    circle_y = -3950;
    circle_x = +2050;
    monst.y = -5000;
    monst.x = 1350;
    pole3_x = 1380;
    pole3_y = -5000;
    M = 0;
    V + 10;
    VV + 20;
    PlaySound(Monsterdead);
    }
    if ((int)ast.y == 480 && M == 0){
    ast.x = 300;
    ast.y = -5000;
    circle_y = -3950;
    circle_x = +1350;
    M++;
    V + 5;
    VV + 10;
    }
    //meteorite posotion
    //mob position
    //mob position
  DrawTextureRec(monster,Rmonst,monst,WHITE);

  // Control
  if (position.x >= 0.0 && position.x <=hei && position.y >= 0 && position.y <=GAME_HEIGHT){
    if (IsKeyDown(KEY_LEFT)){
    realpose.x = realpose.x - 15;  
    pole_x = pole_x - VV;
    pole8_x = pole8_x - VV;
    }
    if (IsKeyDown(KEY_RIGHT)){
    realpose.x = realpose.x + 15;  
    pole_x = pole_x +VV;
    pole8_x = pole8_x + VV;
    }
    if (IsKeyDown(KEY_DOWN)){
    realpose.y = realpose.y + 15;  
    pole_y = pole_y +VV;
    pole8_y = pole8_y +VV;
    }
      if (IsKeyDown(KEY_UP)){
    realpose.y = realpose.y - 15;  
    pole_y = pole_y -VV;
    pole8_y = pole8_y -VV;
    }
    if (IsKeyDown(KEY_SPACE) && PMiss.y > 7000 && waiste == 0 ){  
    PlaySound(Shot);
    PMiss.x = realpose.x * -1;
    PMiss.y = realpose.y * -1;
    pole4_x = PMiss.x * -1;
    pole4_y = PMiss.y * -1;
    pole4_x = pole4_x + 40;
    pole4_y = pole4_y + 299;
    waiste++;
    f++;
    frameconter2 = 0;
    intframe2 = 0;
    }
    if (IsKeyDown(KEY_SPACE) && PMiss.y > 7000 && f == 0 && PMiss4.y > 1500){  
    PlaySound(Shot);
    PMiss.x = realpose.x * -1;
    PMiss.y = realpose.y * -1;
    pole4_x = PMiss.x * -1;
    pole4_y = PMiss.y * -1;
    pole4_x = pole4_x + 40;
    pole4_y = pole4_y + 299;
    f++;
    frameconter2 = 0;
    intframe2 = 0;
    }
    if (IsKeyDown(KEY_SPACE) && PMiss2.y > 3800 && f == 1 && PMiss.y > 1500){  
    PlaySound(Shot);
    PMiss2.x = realpose.x * -1;
    PMiss2.x = PMiss2.x - 55;
    PMiss2.y = realpose.y * -1;
    pole5_x = PMiss2.x * -1;
    pole5_y = PMiss2.y * -1;
    pole5_x = pole5_x +40;
    pole5_y = pole5_y +299;
    f++;
    frameconter2 = 0;
    intframe2 = 0;
    }
    if (IsKeyDown(KEY_SPACE) && PMiss3.y > 3800 && f == 2 && PMiss2.y > 1500){  
    PlaySound(Shot);
    PMiss3.x = realpose.x * -1;
    PMiss3.x = PMiss3.x - 330;
    PMiss3.y = realpose.y * -1;
    pole6_x = PMiss3.x * -1;
    pole6_y = PMiss3.y * -1;
    pole6_x = pole6_x + 40;
    pole6_y = pole6_y + 300;
    f++;
    frameconter2 = 0;
    intframe2 = 0;
    }
    if (IsKeyDown(KEY_SPACE) && PMiss4.y > 3800 && f == 3 && PMiss3.y > 1500){  
    PlaySound(Shot);
    PMiss4.x = realpose.x * -1;
    PMiss4.x = PMiss4.x -390;
    PMiss4.y = realpose.y * -1;
    pole7_x = PMiss4.x * -1;
    pole7_y = PMiss4.y * -1;
    pole7_x = pole7_x + 41;
    pole7_y = pole7_y + 290;
    whait = 1;
    f=0;
    frameconter2 = 0;
    intframe2 = 0;
    }
  }
    //control 
    DrawTexturePro(TMissile,DMiss,DMiss,PMiss,0,WHITE); 
    DrawTexturePro(TMissile2,DMiss,DMiss,PMiss2,0,WHITE); 
    DrawTexturePro(TMissile3,DMiss,DMiss,PMiss3,0,WHITE); 
    DrawTexturePro(TMissile4,DMiss,DMiss,PMiss4,0,WHITE); 
    DrawTextureRec(playership,Rshep,realpose,WHITE);
    DrawTexturePro(explosion,Dex0,Dex0,Pex,0,WHITE);
    DrawTexturePro(explosion,Dex1,Dex1,Pex1,0,WHITE);
    DrawTexturePro(explosion,Dex2,Dex2,Pex2,0,WHITE);
    DrawTexturePro(explosion,Dex3,Dex3,Pex3,0,WHITE);
    printf("%d. %d.\n",(int)realpose.x,(int)realpose.y);
    printf("%d, %d.\n",(int)ast.x,(int)ast.y);
    printf("Missile %d. %d.\n",(int)PMiss.x,(int)PMiss.y);
    if (gameover == false){
    ast.y = ast.y + V;
    monst.y = monst.y +20;
    monst.x = monst.x -2;
    pole3_y = pole3_y +20;
    pole3_x = pole3_x -2;
    circle_y += V;
    PMiss.y = PMiss.y + 20;
    PMiss2.y = PMiss2.y + 20;
    PMiss3.y = PMiss3.y + 20;
    PMiss4.y = PMiss4.y + 20;
    pole7_y = pole7_y -20;
    pole4_y = pole4_y -20;
    pole5_y = pole5_y -20;
    pole6_y = pole6_y -20;
    Pex.y = Pex.y - 20;
    Pex1.y = Pex1.y - 20;
    Pex2.y = Pex2.y - 20;
    Pex3.y = Pex3.y - 20;
    }
     if (intframe2 >= 1){
    frameconter2++;
    }
    if (intframe >= 1){
    frameconter++;
    }
//sceamer

//
//explosion! explosion! explosion! explosion! explosion! explosion! explosion! explosion! explosion! explosion!
 if (Missile1){
 Pex.y = PMiss.y;
 Pex.x = PMiss.x;
 Pex.x = Pex.x +100;
 Pex.y = Pex.y -100;
 monst.y = monst.y +500;
 monst.x = monst.x -2;
 PMiss.y = +3600;
 PlaySound(Monsterdead);
 pole3_y = pole3_y +500;
 pole3_x = pole3_x -2;
 win = 1;
 }
 if (whait == 1){
 whait = 0;
 }  
 if (Missile3){
 Pex.y = PMiss3.y;
 Pex.x = PMiss3.x;
 Pex.x = Pex.x +100;
 Pex.y = Pex.y -100;
 monst.y = monst.y +500;
 monst.x = monst.x -2;
 PMiss3.y = +3600;
 PlaySound(Monsterdead);
 pole3_y = pole3_y +500;
 pole3_x = pole3_x -2;
 win = 1;
 }
 if (Missile4){
 Pex.y = PMiss4.y;
 Pex.x = PMiss4.x;
 Pex.x = Pex.x +100;
 Pex.y = Pex.y -100;
 monst.y = monst.y +500;
 monst.x = monst.x -2;
 PlaySound(Monsterdead);
 pole3_y = pole3_y +500;
 pole3_x = pole3_x -2;
 PMiss4.y = +3600;
 win = 1;
 }
  if (MissileMeteorite1){
  intframe2 = 1;
  const Vector2 temp = PMiss;
  Pex = temp;
  Pex.x = Pex.x +100;
  Pex.y = Pex.y -100;
  PMiss.y = PMiss.y+5600;
  pole4_y = pole4_y+5600;
  intframe = 1;
  }
  whait = 0;
  if (MissileMeteorite2){
  intframe2 = 1;
  const Vector2 temp = PMiss2;
  Pex = temp;
  Pex.x = Pex.x +100;
  Pex.y = Pex.y -100;
  PMiss2.y = PMiss2.y+5600;
  pole5_y = pole5_y+5600;
  intframe = 1;
  }
  if (MissileMeteorite3){
  intframe2 = 1;
  const Vector2 temp = PMiss3;
  Pex = temp;
  Pex.x = Pex.x +100;
  Pex.y = Pex.y -100;
  PMiss3.y = PMiss3.y+5600;
  pole6_y = pole6_y+5600;
  intframe = 1;
  }
  if (MissileMeteorite4){
  intframe2 = 1;
  const Vector2 temp = PMiss4;
  Pex = temp;
  Pex.x = Pex.x +100;
  Pex.y = Pex.y -100;
  PMiss4.y = PMiss4.y+5600;
  pole7_y = pole7_y+5600;
  intframe = 1; 
  }
  if(frameconter2 == 1){
  PlaySound(Sexplosion);
  }
  if(frameconter> 10){
  Pex1 = Pex;
  Pex1.x = Pex1.x +240;
  Pex1.y = Pex1.y ;
  }
  if(frameconter> 15){
  Pex1.y = Pex1.y -10000;
  Pex2 = Pex;
  Pex2.x = Pex2.x +550;
  Pex2.y = Pex2.y ;
  }
  if(frameconter> 20){
  Pex2.y = Pex2.y -10000;
  Pex3 = Pex;
  Pex3.x = Pex3.x +920;
  Pex3.y = Pex3.y ;
  }
  if(frameconter> 30){
  StopSound(Sexplosion);
  Pex3.y = Pex3.y -10000;
  Pex.y = Pex.y -10000;
  intframe = 0;
  frameconter = 0;
  }
  
  // pole 4 miss 1 pole 5 miss 2  pole 6 miss 3 pole 7
  // explosion! explosion! explosion! explosion! explosion! explosion! explosion! explosion! explosion! explosion!
  // deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf
  if(collision || !Outofmap || mobhitbox || collision2){
  gameover = true;
  ClearBackground(BLACK);
  Af = 0;
  StopSoundMulti(); 
  StopSound(Play);
  StopSound(music);
  while (mort< 1){
  UnloadTexture(playership);
  UnloadTexture(asteroid);
  UnloadTexture(monster);
  UnloadTexture(img2d);
  UnloadTexture(explosion);
  UnloadTexture(TMissile);
  UnloadTexture(TMissile2);
  UnloadTexture(TMissile3);
  UnloadTexture(TMissile4);
  PlaySound(Dead);
  mort++;
  }  
  ClearBackground(BLACK);
  DrawText("GAME OVER",1420,-1388,200,RED);
  EndDrawing();
  continue;
  }
  // deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf  deaf
  // win win win win win win win win win win win win win win win win win win win win win win win win
  if (win == 1){
  ClearBackground(BLACK);
  gameover = true;
  Af = 0;
  ClearBackground(BLACK);
  StopSoundMulti(); 
  StopSound(Play);
  StopSound(music);
  while (vie< 1){
  UnloadTexture(playership);
  UnloadTexture(asteroid);
  UnloadTexture(monster);
  UnloadTexture(img2d);
  UnloadTexture(explosion);
  UnloadTexture(TMissile);
  UnloadTexture(TMissile2);
  UnloadTexture(TMissile3);
  UnloadTexture(TMissile4);
  PlaySound(Youwin);
  PlaySound(SWin);
  vie++;
  }  
  ClearBackground(BLACK);
  DrawText("You Win",1600,-1388,200,GREEN);
  EndDrawing();
  continue;
  }
  // win win win win win win win win win win win win win win win win win win win win win win win win
  else{
  
    //update edges of circle
    l_circle = circle_x - circle_radius;
    r_circle = circle_x + circle_radius;
    u_circle = circle_y - circle_radius;
    b_circle = circle_y + circle_radius;
    
    
    //update player
    l_pole = pole_x;
    r_pole = pole_x + pole_width;
    u_pole = pole_y;
    b_pole = pole_y + pole_height;
    //
    l_pole8 = pole8_x;
    r_pole8 = pole8_x + pole8_width;
    u_pole8 = pole8_y;
    b_pole8 = pole8_y + pole8_height;
    //update monstre
    l_pole3 = pole3_x;
    r_pole3 = pole3_x + pole3_width;
    u_pole3 = pole3_y;
    b_pole3 = pole3_y + pole3_height;
    // update missile 1
    l_pole4 = pole4_x;
    r_pole4 = pole4_x + pole4_width;
    u_pole4 = pole4_y;
    b_pole4 = pole4_y + pole4_height;
    // update missile 2
    l_pole5 = pole5_x;
    r_pole5 = pole5_x + pole5_width;
    u_pole5 = pole5_y;
    b_pole5 = pole5_y + pole5_height;
    // update missile 3
    l_pole6 = pole6_x;
    r_pole6 = pole6_x + pole6_width;
    u_pole6 = pole6_y;
    b_pole6 = pole6_y + pole6_height;
    // update missile 4
    l_pole7 = pole7_x;
    r_pole7 = pole7_x + pole7_width;
    u_pole7 = pole7_y;
    b_pole7 = pole7_y + pole7_height;
    //========================================================
    //update collision
    collision = (l_circle < r_pole) && (r_circle > l_pole) && (u_circle < b_pole) && (b_circle > u_pole); 
    collision2 = (l_circle < r_pole8) && (r_circle > l_pole8) && (u_circle < b_pole8) && (b_circle > u_pole8); 
    Outofmap = (l_pole2 < r_pole) && (r_pole2 > l_pole) && (u_pole2 < b_pole) && (b_pole2 > u_pole); 
    mobhitbox = (l_pole3 < r_pole) && (r_pole3 > l_pole) && (u_pole3 < b_pole) && (b_pole3 > u_pole); 
    Missile1 = (l_pole3 < r_pole4) && (r_pole3 > l_pole4) && (u_pole3 < b_pole4) && (b_pole3 > u_pole4); 
    Missile2 = (l_pole3 < r_pole5) && (r_pole3 > l_pole5) && (u_pole3 < b_pole5) && (b_pole3 > u_pole5); 
    Missile3 = (l_pole3 < r_pole6) && (r_pole3 > l_pole6) && (u_pole3 < b_pole6) && (b_pole3 > u_pole6); 
    Missile4 = (l_pole3 < r_pole7) && (r_pole3 > l_pole7) && (u_pole3 < b_pole7) && (b_pole3 > u_pole7); 
    MissileMeteorite1 = (l_circle < r_pole4) && (r_circle > l_pole4) && (u_circle < b_pole4) && (b_circle > u_pole4); 
    MissileMeteorite2 = (l_circle < r_pole5) && (r_circle > l_pole5) && (u_circle < b_pole5) && (b_circle > u_pole5);
    MissileMeteorite3 = (l_circle < r_pole6) && (r_circle > l_pole6) && (u_circle < b_pole6) && (b_circle > u_pole6); 
    MissileMeteorite4 = (l_circle < r_pole7) && (r_circle > l_pole7) && (u_circle < b_pole7) && (b_circle > u_pole7);  
    //sizeofmap  
    //DrawRectangle(pole2_x,pole2_y,pole2_width,pole2_height,BLUE); 
    //player
    //DrawRectangle(pole_x,pole_y,pole_width,pole_height,BLUE);  
    //DrawRectangle(pole8_x,pole8_y,pole8_width,pole8_height,BLUE);  
    //draws meteorite
    ///DrawCircle(circle_x,circle_y,circle_radius,RED);              
    //mob
    //DrawRectangle(pole3_x,pole3_y,pole3_width,pole3_height,YELLOW);       
    //missile1   
    //DrawRectangle(pole4_x,pole4_y,pole4_width,pole4_height,YELLOW);       
    //missile2   
    //DrawRectangle(pole5_x,pole5_y,pole5_width,pole5_height,YELLOW);       
    //missile3
    //DrawRectangle(pole6_x,pole6_y,pole6_width,pole6_height,YELLOW);       
    //missile4     
    //DrawRectangle(pole7_x,pole7_y,pole7_width,pole7_height,YELLOW);    
  }
  //.................................................................................................
EndDrawing();
}
//UnloadTexture(img);
UnloadSound(Play);
UnloadSound(Sintro);
UnloadSound(music);
UnloadSound(Shot);
UnloadSound(SWin);
UnloadSound(Youwin);
UnloadSound(Sexplosion);
UnloadImage(img);
UnloadTexture(playership);
UnloadTexture(asteroid);
UnloadTexture(monster);
UnloadTexture(img2d);
CloseAudioDevice();
CloseWindow();
}

