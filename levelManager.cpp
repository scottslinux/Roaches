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
