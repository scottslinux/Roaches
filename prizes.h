#pragma once

#include<iostream>
#include<vector>
#include "raylib.h"
#include "media.h"
#include "Hero.h"
#include "levelManager.h"

class prizes
{

    
public:

    Vector2 pos;
    float scale;
    int prizevalue;
    int frame2;

    bool caught;
    bool display;
    


    prizes(/* args */);
    void displayprizes();
    
};

