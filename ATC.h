#pragma once

#include <iostream>
#include "raylib.h"
#include "insect.h"
#include "Hero.h"
#include "swarm.h"
#include "garbage.h"

//This module will consist of static methods used to detect
//collisions and set flags. It may or may not end up implementing 
//the results of the collision..let's let it evolve.

class ATC
{

public:


    ATC();  // constructor....may not use as its all static

    static bool collide(swarm& herd,Hero& player);    //pass the swarm by reference
    static bool collide(swarm& herd,Vector2,Vector2);        //roach swarm and start/end of laser line
    static bool collide(garbage& trash,Rectangle playerrect);   //player and the prizes


    


};

