#pragma once

#include <iostream>
#include <math.h>
#include <vector>
#include "raylib.h"
#include "swarm.h"





struct shot
{
    Vector2 pos;
    Vector2 vel;
    float theta;
    float scale;
    double last_time;

    Rectangle colrect;

};
//==========================================
class missile
{

static int laserpower;      //this was wrongfully declared outside of the class :(
private:
    int activeshots;    //leave as a reminder of what could have been
    


public:
    //keep it real...single rocket for now
    shot rocket;   //make publicly available






    missile(/* args */);    //constructor
    //fire a missile and provide the player pos and vel to determine pos
    void fireshot(Vector2 pos, int direction,swarm& herd); 
    void updatemissile();
    void drawmissile();
    void killroach();
    static int getremainlaser();
    bool fireflag;
    double laserdelay;
    double firetime;


    void playlasersound();
    Vector2 targetVector(swarm& localherd, Vector2 start, Vector2 end,int dir);
    


};



















