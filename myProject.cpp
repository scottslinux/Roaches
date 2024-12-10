#include <iostream>
#include "raylib.h"
#include "insect.h"
#include "swarm.h"
#include "Hero.h"
#include "missile.h"
#include "media.h"
<<<<<<< HEAD
#include "scoreboard.h""
=======
#include "scoreboard.h"
>>>>>>> bf4eed2 (Nailed the Memory Error)


void collisionChecker(swarm herd, Hero man);    //forward prototype

<<<<<<< HEAD

//---------------------------------------------------------
=======
bool collchcecker(int, int); //prototype


>>>>>>> bf4eed2 (Nailed the Memory Error)
int main()
{
    InitWindow(3500,2000,"TEST WINDOW");
    SetTargetFPS(60);
    InitAudioDevice();



    swarm myswarm(10);
    Hero guy;
    missile shooter;
<<<<<<< HEAD
    scoreboard screentitles;
=======
    scoreboard titlesandscores;
>>>>>>> bf4eed2 (Nailed the Memory Error)

    media::loadMediaFiles();        // Load up all of the sights and sounds!

    int totalroaches=myswarm.roaches.size();

    
    PlayMusicStream(media::backgroundmusic);
    

    while(!WindowShouldClose())
    {
        UpdateMusicStream(media::backgroundmusic);

        BeginDrawing();

<<<<<<< HEAD
            
            screentitles.drawscreenframe();

=======

            titlesandscores.drawscreenframe();
>>>>>>> bf4eed2 (Nailed the Memory Error)
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
<<<<<<< HEAD
//====================================================================================
void collisionChecker(swarm herd, Hero man)
{

    




    return;

}
=======

>>>>>>> bf4eed2 (Nailed the Memory Error)
