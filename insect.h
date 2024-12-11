#pragma once

#include<iostream>
#include<cmath>
#include "raylib.h"


enum life {Dead,Alive,Dying};   //GLOBAL life flag 0-2

class insect
{

private:
    
    int spritedimension{128};

    Vector2 pos;        //x,y coordinates
    Vector2 vel;        //x,y vel
    float rotation{0.0f};     //sprite rotation
    float scale{1.0f};
    double last_time{0};   //time stamp for last movement
    int frame{0};          //current frame of animation
    double frametimer{0};
    Vector2 spritecntr{0,0};

    life vitality{Alive};      //create variable of type life
    bool colliding{false};
    bool alive{true};
    double deathclock{0};


    Rectangle colrec{0.0f, 0.0f, 0.0f, 0.0f};  // Default rectangle
   public:
   const float SPRITESQRSIZE=128.0F;

 

    insect();     //constructor

    void updateroachpos();
    void killroach();       //maybe in swarm manager
    void drawroach();
    double radians2degrees(double rads);
    void adjustroachsize();
    Vector2 getbugpos();
    float getbugscale();
    

};





