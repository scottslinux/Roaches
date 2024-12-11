#include "missile.h"
#include "swarm.h"
#include "media.h"
#include "ATC.h"


int missile::laserpower={0};
//==============================================//
missile::missile()  //constructor defiition
{
    //initializing everything to zero at start
    

    rocket.pos.x=0;
    rocket.pos.y=0;
    rocket.vel.x=0;
    rocket.vel.y=0;

    rocket.theta=0;
    rocket.last_time=0;

    laserpower=250; //starting laser power
    laserdelay=2.0;

    //check to see
    


}
//==============================================//
//   get a shot off passing hero pos and direction
void missile::fireshot(Vector2 pos, int direction,swarm& herd)
{
    if(GetGamepadAxisMovement(0,5)>0 && laserpower>0 && laserdelay>0)
    {

        missile::playlasersound();


        fireflag=true;

        Vector2 correctedxypos;
        Vector2 startshot;
        Vector2 endshot;
        --laserpower;
        if (laserpower<=0)
            laserpower=0;


        if(direction==1)       //hero looking right
        {
            correctedxypos.x=pos.x+375;
            correctedxypos.y=pos.y+60;

            float gunangle=35*(M_PI/180.0);  //convert to radians
            startshot={correctedxypos.x,correctedxypos.y};

            endshot={correctedxypos.x+(2000*cos(gunangle)),
            correctedxypos.y-(2000*sin(gunangle))};
        }
        else       //hero looking left
        {
            correctedxypos.x=pos.x+20;
            correctedxypos.y=pos.y+50;

            float gunangle=145*(M_PI/180.0);  //convert to radians
            startshot={correctedxypos.x,correctedxypos.y};

            endshot={correctedxypos.x+(2000*cos(gunangle)),
            correctedxypos.y-(2000*sin(gunangle))};
        }
        Color shotcolor={255,186,49,100};
        Color lasercolor={255,138,253,150};
        Color lasercolor2={255,138,253,50};

        
        endshot=missile::targetVector(herd,startshot,endshot,direction);

        DrawLineEx(startshot,endshot,80,lasercolor2);
        DrawLineEx(startshot,endshot,GetRandomValue(10,60),lasercolor);

        DrawLineEx(startshot,endshot,GetRandomValue(3,20),WHITE);

        
        fireflag=false;

        ATC::collide(herd,startshot,endshot);   //check for a hit on the roaches

        
        
    }


}


//==============================================//
int missile::getremainlaser()
{   return laserpower; }

//==============================================
void missile::playlasersound()
{
    //missile::lasershot=LoadSound("resources/Laser.wav");
    PlaySound(media::lasershot);
    

}

//================================================
//  try again to find the distance to the first roch

Vector2 missile::targetVector(swarm& localherd, Vector2 start, Vector2 end,int dir)
{
    float segsize=100.0f;
    float anglerads=35*(M_PI/180.0);

    Vector2 A=start;
    Vector2 B;

    B.x=A.x+(segsize*dir);
    B.y=A.y-(tan(anglerads)*segsize);

    for(int i=0;i<10;i++)
    {
        B.x=A.x+(segsize*i*dir);
        B.y=A.y-(tan(anglerads)*(segsize*i));

        if (ATC::collide(localherd,start,B))
            return(B);



    }

    return B;



}