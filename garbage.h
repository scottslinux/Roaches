#pragma once

#include <iostream>
#include <vector>
#include "raylib.h"
#include "media.h"
#include "Hero.h"
#include "levelManager.h"



struct blast_particle    //
{   
    Vector2 pos = {0, 0};  // Default position
    Vector2 vel = {0, 0};  // Default velocity
    bool life=true;        // Default life status
};

//Modern way brother...initialize the values in the constructor!!!
class food {
public:
    Vector2 pos={1000,1000};  // Default position
    float scale = 0.4;     // Default scale
    float rotation = 0;    // Default rotation
    int prizevalue = 0;    // Default prize value
    int frame = 0;         // Default frame
    Vector2 origin = {0, 0}; // Default origin
    bool caught = false;   // Default caught status
    bool display = true;   // Default display status

    std::vector<blast_particle> blast;  // Default blast status


    food();  // Constructor
};

class garbage {
    // represents a collection of rotten food items

private:

public:
    int itemsinGarbage;
    std::vector<food> prizes;

    garbage(int num);  // constructor creates a bunch of rotten food = garbage
    void displayGarbage();

};