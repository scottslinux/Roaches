#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iomanip>
#include <iostream>
#include <sstream>
#include "raylib.h"
#include "Hero.h"
#include "missile.h"



class scoreboard
{
private:
    int playerlives;
    int score;
    float playerhealth;
    int level;
    double timer;

    
    Font titlefont;
    Texture2D lifeIcon;



public:
    scoreboard();

    void drawscreenframe();
    void updateScore(int);
    void killplayer();
    

};


















#endif