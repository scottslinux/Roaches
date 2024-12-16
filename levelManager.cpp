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



levelManager::levelManager()
{
}
//====================================================
void levelManager::splashscreen()
{
    PlayMusicStream(media::splashmusic);

    while(!IsKeyPressed(KEY_SPACE))
        {

      UpdateMusicStream(media::splashmusic);
        BeginDrawing();



        Rectangle source={0,0,media::splash.width,media::splash.height};
        Rectangle destin={0,0,GetScreenWidth(),GetScreenHeight()};
        DrawTexturePro(media::splash,source,destin,{0,0},0,WHITE);

        EndDrawing();

        }


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

    while(!WindowShouldClose())
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

        
  

    }




}