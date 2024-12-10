#include "swarm.h"
#include <vector>


//=======================================
swarm::swarm(int num)
{
    
    //roaches.resize(num);    //create the roaches
    roachesinswarm=num;

    for (int i = 0; i < num; ++i) 
            roaches.emplace_back();

    
        


    
    
   
}
//=======================================
void swarm::displayswarm()
{
    for(int i=0;i<roaches.size();i++)
    {
        roaches[i].updateroachpos();
        roaches[i].drawroach();

    }

    return;
}

//=======================================
bool check4collision()
{

    
    


}