#pragma once

#include <vector>
#include "insect.h"



class swarm
{
private:
    
   

public:

    std::vector<insect> roaches;
    int roachesinswarm;

    swarm(int num);      //constructor with number of bugs
    void displayswarm();    //show it
    bool collischeck(Rectangle);

};



