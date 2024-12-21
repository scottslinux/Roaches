#pragma once

#include<iostream>
#include<vector>
#include "raylib.h"
#include "media.h"
#include "Hero.h"
#include "levelManager.h"

class food
{
    //class representing individual food items
    
public:

    Vector2 pos;
    float scale;
    float rotation;
    int prizevalue;
    int frame;
    Vector2 origin;

    bool caught;
    bool display;
    


    food(/* args */);   //constructor
    
};



class garbage
{
    //represents a collection of rotten food items

private:


public:
    int itemsinGarbage;
    std::vector<food> prizes;


    garbage(int num);   //constructor creates a bunch of rotten food = garbage
    void displayGarbage();
};


