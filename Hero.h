#ifndef HERO_H
#define HERO_H

#include <raylib.h>
#include <iostream>




class Hero
{
private:
    

    Vector2 pos;
    Vector2 vel;
    Vector2 origin;

    Rectangle colrec;   //this sprites collision rectangle

    double frametimer;
    double delta_t;

    float rotation;     //sprite rotation
    float scale;

    int frame;          //current frame of animation
    int spritesqr;
    int direction;
    int vitality;      //create variable of type life

    bool directionflag;
    
    


public:
    

    Hero(/* args */);  //Constructor

    int collisioneventcountdown;    //keep these public so other routines can mark collisions
    bool colliding;

    void updateplayer();
    void killplayer();
    void drawplayer();
    void controllerinput();
    Rectangle getplayerrect();
    Vector2 getplayerpos();
    Vector2 getplayervel();
    int getplayerdirection();

};

#endif