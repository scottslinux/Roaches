#include <iostream>
#include "raylib.h"
#include "insect.h"
#include "swarm.h"
#include "Hero.h"
#include "missile.h"
#include "media.h"



int main()
{
    InitWindow(2500,2000,"TEST WINDOW");
    SetTargetFPS(60);
    InitAudioDevice();



    swarm myswarm(10);
    Hero guy;
    missile shooter;

    media::loadMediaFiles();        // Load up all of the sites and sounds!

    
    PlayMusicStream(media::backgroundmusic);
    

    while(!WindowShouldClose())
    {
        UpdateMusicStream(media::backgroundmusic);

        BeginDrawing();

            DrawTexture(media::sink,0,0,WHITE);
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