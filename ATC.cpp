#include <iostream>
#include "raylib.h"
#include "insect.h"
#include "Hero.h"
#include "swarm.h"
#include "ATC.h"



//================================================================
//
//              ATC -Air Traffic Control Collision Monitor
//================================================================

ATC::ATC()      //constructor
{

}
//***********************************************************************************
bool ATC::collide(swarm& herd,Hero& player)    //pass the swarm by reference and the player.
{
    
    //check if roach contacts and kills player
    for(int i=0;i<10;i++)
    {
        if(CheckCollisionCircleRec({herd.roaches[i].getbugpos()}
            ,60*herd.roaches[i].getbugscale(),player.getplayerrect()))
            {
                if (herd.roaches[i].isAlive())
                {

                player.killplayer();
                std::cout<<"Collision with roach # "<<i<<std::endl;
                std::cout<<"isAlive() returns: "<<herd.roaches[i].isAlive()<<std::endl;
                return true; 
                }
            }
            
            
    }

    return false;
}
//***********************************************************************************
bool ATC::collide(swarm& herd,Vector2 startpt,Vector2 endpt)    
{
        ///roach swarm and start/end of laser line
        for(int i=0;i<herd.roachesinswarm;i++)
        {
            if(CheckCollisionCircleLine(herd.roaches[i].getbugpos(),
                60*herd.roaches[i].getbugscale(),startpt,endpt))
                {
                  if (herd.roaches[i].isAlive())
                  {
                    herd.roaches[i].killroach();    //simple method sets alive to 0
                    
                    return true;
                  }
                }



        }

    return false;

}