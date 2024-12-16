#include <iostream>
#include "raylib.h"
#include "insect.h"
#include "swarm.h"
#include "Hero.h"
#include "missile.h"
#include "media.h"
#include "scoreboard.h"
#include "ATC.h"



int main()
{
    // Set the configuration flag to create an undecorated window
    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(GetMonitorWidth(0),GetMonitorHeight(0),"TEST WINDOW");
    SetTargetFPS(60);
    InitAudioDevice();

    double start_time=GetTime();  //INITIALIZE THE TIME VARIABLES
    double delta_time=0;



    swarm myswarm(40);
    Hero guy;
    missile shooter;
    scoreboard titlesandscores;

    media::loadMediaFiles();        // Load up all of the sights and sounds!

    int totalroaches=myswarm.roaches.size();

    
    PlayMusicStream(media::backgroundmusic);
    
    start_time=GetTime();    //initialize the last_time to current time


//              ​‌‌‍⁡⁣⁢⁣𝕄𝔸𝕀ℕ 𝔾𝔸𝕄𝔼 𝕃𝕆𝕆ℙ⁡​

    while(!WindowShouldClose())
    {
        //              ⁡⁣⁢⁣𝗗𝗘𝗟𝗧𝗔-𝗧𝗜𝗠𝗘 𝗖𝗔𝗟𝗖𝗨𝗟𝗔𝗧𝗜𝗢𝗡𝗦⁡
        delta_time=GetTime()-start_time;;    //𝗰𝗮𝗹𝗰 𝗵‍𝗼𝘄 𝗹𝗼𝗻𝗴 𝘄𝗲 𝘄𝗲𝗿𝗲 𝗶𝗻 𝘁𝗵𝗲 𝗹𝗼𝗼𝗽
        start_time=GetTime();               //𝘀𝗲𝘁 𝘁𝗵𝗲 𝘁𝗶𝗺𝗲 𝗯𝗲𝗳𝗼𝗿𝗲 𝘄𝗲 𝗴𝗼 𝘁𝗵𝗿𝘂 𝘁𝗵𝗲 𝗹𝗼𝗼𝗽
                                            //𝗮𝗻𝗱 𝘁𝗵𝗲𝗻 𝗰𝗼𝗺𝗽𝗮𝗿𝗲 𝗶𝘁 𝘁𝗼 𝘁𝗵𝗲 𝗰𝘂𝗿𝗿𝗲𝗻𝘁 𝘁𝗶𝗺𝗲.⁡

        
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

    //unload everything outside of the main loop or segmentation error will occurr
    
    media::unloadMediaFiles();



    return 0;
    
}
