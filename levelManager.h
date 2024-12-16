#pragma once

#include <iostream>
#include "raylib.h"
#include "Hero.h"
#include "media.h"
#include "ATC.h"
#include "insect.h"
#include "missile.h"
#include "scoreboard.h"
#include "swarm.h"

class levelManager
{


public:

    static int gamestate;  //0=exiting, 1=playing, 2=splash screen hold
    static int level;

    levelManager();
    void splashscreen();
    void playlevel();
    
};



