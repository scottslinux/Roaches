#include "levelManager.h"

#include <iostream>
#include "raylib.h"
#include "Hero.h"
#include "media.h"
#include "ATC.h"
#include "insect.h"
#include "missile.h"
#include "scoreboard.h"
#include "swarm.h"
#include "media.h"
#include "timer.h"

int levelManager::gamestate={0};
int levelManager::level={0};
int levelManager::playerlives={0};
bool levelManager::playerdead={0};

levelManager::levelManager()
{
  gamestate=2;  //start off holding at splash screen
  level=0;      //start off 1st difficulty level
  playerlives=3; //start with 3 players
  playerdead=false;

}
//====================================================
void levelManager::splashscreen()
{
    PlayMusicStream(media::splashmusic);
    
    swarm solobug(3);

    while(!IsKeyPressed(KEY_SPACE) && !IsKeyPressed(KEY_X))
        {

      UpdateMusicStream(media::splashmusic);
        BeginDrawing();


        //Draw the Roach Photo
        Rectangle source={0,0,media::splash.width,media::splash.height};
        Rectangle destin={0,0,GetScreenWidth(),GetScreenHeight()};
        DrawTexturePro(media::splash,source,destin,{0,0},0,WHITE);

        DrawTextPro(media::titlefont,"PRESS SPACEBAR TO PLAY",{GetScreenWidth()/2-600,GetScreenHeight()-300}
                                                                ,{0,0},0,120,5,YELLOW);
        DrawTextPro(media::titlefont,"     X TO EXIT",{GetScreenWidth()/2-400,GetScreenHeight()-100},{0,0},0,80,5,YELLOW);

        solobug.displayswarm();


        EndDrawing();

        

        }
      if(IsKeyPressed(KEY_X))
        levelManager::gamestate=0;      //set the state to exit the game

    return;

}
//====================================================
void levelManager::playlevel()
{

double start_time=GetTime();  //INITIALIZE THE TIME VARIABLES
    double delta_time=0;


    
    swarm myswarm(40);
    Hero guy;
    missile shooter;
    scoreboard titlesandscores;


    int totalroaches=myswarm.roaches.size();

    
    PlayMusicStream(media::backgroundmusic);
    SetMusicVolume(media::backgroundmusic,0.2);


    start_time=GetTime();    //initialize the last_time to current time



//              ​‌‌‍⁡⁣⁢⁣𝕄𝔸𝕀ℕ 𝔾𝔸𝕄𝔼 𝕃𝕆𝕆ℙ⁡​

    while ((levelManager::playerdead==false) && (!WindowShouldClose()))
    {
        //              ⁡⁣⁢⁣𝗗𝗘𝗟𝗧𝗔-𝗧𝗜𝗠𝗘 𝗖𝗔𝗟𝗖𝗨𝗟𝗔𝗧𝗜𝗢𝗡𝗦⁡
        delta_time=GetTime()-start_time;;    //𝗰𝗮𝗹𝗰 𝗵‍𝗼𝘄 𝗹𝗼𝗻𝗴 𝘄𝗲 𝘄𝗲𝗿𝗲 𝗶𝗻 𝘁𝗵𝗲 𝗹𝗼𝗼𝗽
        start_time=GetTime();               //𝘀𝗲𝘁 𝘁𝗵𝗲 𝘁𝗶𝗺𝗲 𝗯𝗲𝗳𝗼𝗿𝗲 𝘄𝗲 𝗴𝗼 𝘁𝗵𝗿𝘂 𝘁𝗵𝗲 𝗹𝗼𝗼𝗽
                                            //𝗮𝗻𝗱 𝘁𝗵𝗲𝗻 𝗰𝗼𝗺𝗽𝗮𝗿𝗲 𝗶𝘁 𝘁𝗼 𝘁𝗵𝗲 𝗰𝘂𝗿𝗿𝗲𝗻𝘁 𝘁𝗶𝗺𝗲.⁡
        bool splashflag=false;  //has not been shown yet
        
        UpdateMusicStream(media::backgroundmusic);

        BeginDrawing();

            
            titlesandscores.drawscreenframe();
            myswarm.displayswarm();

            guy.updateplayer();
            guy.drawplayer();

            if(guy.getPlayerHealth()==1)    //only shoot when alive
                shooter.fireshot(guy.getplayerpos(),guy.getplayerdirection(),myswarm,delta_time);
            
            ATC::collide(myswarm,guy);

            
                
            



        EndDrawing();

        std::cout<<"trying to leave after esc..from levelman mainrender loop\n";
        levelManager::gamestate=0; //trying to leave game completely
        
  

    }




}