#pragma once
#include<iostream>
#include<cmath>
#include "raylib.h"
#include <vector>


enum life {Dead,Alive,Dying};   //GLOBAL life flag 0-2

class insect
{

private:
    

    Vector2 pos;        //x,y coordinates
    Vector2 vel;        //x,y vel
    Vector2 spritecntr{0,0};

    double frametimer{0};
    double last_time{0};   //time stamp for last movement.
    double deathclock{0};
    double frametimedeath{0};
    static double deltaT;
    static double currtime;



    float rotation{0.0f};     //sprite rotation
    float scale{1.0f};

    int frame{0};          //current frame of animation
    int frame2{0};
    int spritedimension{128};

    bool colliding{false};
    bool alive{true};

    

public:

    life vitality{Alive};      //create variable of type life


    Rectangle colrec{0.0f, 0.0f, 0.0f, 0.0f};  // Default rectangle
   const float SPRITESQRSIZE=128.0F;

 

    insect();     //constructor

    void updateroachpos();
    void killroach();       //maybe in swarm manager
    void drawroach();
    double radians2degrees(double rads);
    void adjustroachsize();
    Vector2 getbugpos();
    float getbugscale();
    int isAlive();
    

};





