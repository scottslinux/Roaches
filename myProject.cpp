#include <iostream>
#include "raylib.h"
#include "insect.h"
#include "swarm.h"
#include "Hero.h"
#include "missile.h"
#include "media.h"
#include "scoreboard.h""


void collisionChecker(swarm herd, Hero man);    //forward prototype


//---------------------------------------------------------
int main()
{
    InitWindow(3500,2000,"TEST WINDOW");
    SetTargetFPS(60);
    InitAudioDevice();



    swarm myswarm(10);
    Hero guy;
    missile shooter;
    scoreboard screentitles;

    media::loadMediaFiles();        // Load up all of the sites and sounds!

    
    PlayMusicStream(media::backgroundmusic);
    

    while(!WindowShouldClose())
    {
        UpdateMusicStream(media::backgroundmusic);

        BeginDrawing();

            
            screentitles.drawscreenframe();

            myswarm.displayswarm();

            guy.updateplayer();
            guy.drawplayer();

            shooter.fireshot(guy.getplayerpos(),guy.getplayerdirection(),myswarm);


            
            

    





        EndDrawing();


  

    }

    //unload everything outside of the main loop or segmentation error will occurr
    
    media::unloadMediaFiles();



    return 0;
    
}
//====================================================================================
void collisionChecker(swarm herd, Hero man)
{

    




    return;

}