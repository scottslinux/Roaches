#include <iostream>
#include "raylib.h"
#include "insect.h"
#include "swarm.h"
#include "Hero.h"
#include "missile.h"
#include "media.h"
#include "scoreboard.h"
#include "ATC.h"


void collisionChecker(swarm herd, Hero man);    //forward prototype

bool collchcecker(int, int); //prototype


int main()
{
    InitWindow(GetMonitorWidth(0),GetMonitorHeight(0),"TEST WINDOW");
    SetTargetFPS(60);
    InitAudioDevice();



    swarm myswarm(10);
    Hero guy;
    missile shooter;
    scoreboard titlesandscores;

    media::loadMediaFiles();        // Load up all of the sights and sounds!

    int totalroaches=myswarm.roaches.size();

    
    PlayMusicStream(media::backgroundmusic);
    

    while(!WindowShouldClose())
    {
        UpdateMusicStream(media::backgroundmusic);

        BeginDrawing();


            titlesandscores.drawscreenframe();
            myswarm.displayswarm();

            guy.updateplayer();
            guy.drawplayer();


            shooter.fireshot(guy.getplayerpos(),guy.getplayerdirection(),myswarm);
            ATC::collide(myswarm,guy);

            
            

    



        EndDrawing();


  

    }

    //unload everything outside of the main loop or segmentation error will occurr
    
    media::unloadMediaFiles();



    return 0;
    
}
