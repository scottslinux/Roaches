#include <iostream>
#include "raylib.h"
#include "insect.h"
#include "swarm.h"
#include "Hero.h"
#include "missile.h"
#include "media.h"
#include "scoreboard.h"
#include "ATC.h"
#include "levelManager.h"





int main()
{
    // Set the configuration flag to create an undecorated window
    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    InitWindow(GetMonitorWidth(0),GetMonitorHeight(0),"TEST WINDOW");
    SetTargetFPS(60);
    InitAudioDevice();
    media::loadMediaFiles();        // Load up all of the sights and sounds!
    levelManager GameBoss;  //instantiate a level Management object--a game instance
    levelManager::gamestate=2;  //0=exiting, 1=playing, 2=splash screen hold

while (!levelManager::gamestate==0)
{
    levelManager::playerdead=false;
    levelManager::playerlives=3;

    //probably need to reset all globals for new game

    GameBoss.splashscreen();

    if(levelManager::gamestate==0)  return 0; //exit chosen--leave the game
            
    while(levelManager::playerlives>0 && (!levelManager::gamestate==0))  //play until all lives exhausted
        {   levelManager::playerdead=false;
            GameBoss.playlevel();
            
        }

}
   
    media::unloadMediaFiles();



    return 0;
    
}
