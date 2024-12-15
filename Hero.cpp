#include "Hero.h"
#include <sstream>
#include <stdio.h>
#include <iomanip>  // For std::fixed and std::setprecision
#include <math.h>
#include "swarm.h"
#include "media.h"






//===============================================
//          constructor

Hero::Hero(){
    pos.x=1200; //starting character position
    pos.y=1200;
    vel.x=0;
    vel.y=0;
    directionflag=false;
    scale=0.75;
    origin={pos.x+512*scale/2,pos.y+512*scale/2};
    

    rotation=0;

    last_time=GetTime();
    frame=0;
    frametimer=0.0;
    const int spritesqr=512;
    delta_t=0;
    direction=1;

    alive=1; //0-dead, 1-alive, 2-dying
    
    colrec={pos.x,pos.y,512*scale,512*scale};  //***dummy values */
    colliding=false;
    collisioneventcountdown=0;


    
        

}
//=============================================
void Hero::updateplayer()
{
    controllerinput();  //in controllerinput(): check for death. Stop moving

    delta_t=GetTime()-last_time;
    frametimer+=delta_t;


    //check bounds before updating position.
    if((pos.x+delta_t*vel.x)>20 && 
        (pos.x+delta_t*vel.x)<GetScreenWidth()-300)
                pos.x+=delta_t*vel.x;

    if((pos.y+delta_t*vel.y)>20 && 
        (pos.y+delta_t*vel.y)<GetScreenHeight()-360)               
                pos.y+=delta_t*vel.y;

    last_time=GetTime();    //update last time moved

    if(frametimer>20/abs(vel.x) || frametimer>20/abs(vel.y))
    {
        
        if(++frame>3) frame=0;  //advance to next frame--reset if needed
        frametimer=0;
    }
    int scaleddim=512*scale;

    //  Painstakingly edited the HIT BOX to adjust the size around the Hero
    colrec={pos.x+(0.3f*scaleddim),pos.y+(0.15f*scaleddim),scaleddim-0.6f*scaleddim,(float)(scaleddim-100)};  //update collision rect
    
    
    //important to set velocity back to zero so walking stops
    vel.x=0;
    vel.y=0;

    

    return;
}

//=============================================
void Hero::drawplayer()
{
    if(alive==2 || alive==0)
    {
        playerdying();  // if the player is dying go to the death animation routine
        return;
    }

/*
    int death;
    if(colliding)
        death=512;
            else   
                death=0;
*/
    Rectangle source={512*frame,0,direction*512,512};
    Rectangle destin={pos.x,pos.y,512*scale,512*scale};
    

    DrawTexturePro(media::heroimage,source,destin,{0,0},0,WHITE);
    //DrawRectangleLinesEx(colrec,5,RED);   //rectangle around player for debugging


    return;
}
//===========================================
void Hero::controllerinput()
{
    if (colliding)      //if dead stop moving
        {
            vel={0,0};
            return;
        }
    std::stringstream ss;
    std::stringstream direc;

    float x=GetGamepadAxisMovement(0,0);
    float y=GetGamepadAxisMovement(0,1);

    if(abs(x)<0.2)x=0;  //remove the jitter
    if(abs(y)<0.2)y=0;  

    

    

    vel.x=500*x;  //translate stick to velocity
    vel.y=500*y;

    //adjust player sprite direction
    if(vel.x>0) 
        {   
            directionflag=false;
            direction=1;
        }
    if(vel.x<0)
        direction=-1;

 


    return;

}
//============================================
Rectangle Hero::getplayerrect()
{
    return colrec;
    
}
//============================================
void Hero::killplayer()
{
    if(alive==2 || alive==0)    //if death sequence already underway
        return;


    alive=2; 
    collisioneventcountdown=1000;
    colliding=true;

    last_time=GetTime();    //Mark the time for the start of the death animation
    frame=0;                //initialize all times going into the animation routine
    last_time=GetTime();
    delta_t=0; 

}
//============================================
Vector2 Hero::getplayerpos()
{
    return(pos);
}
//============================================
Vector2 Hero::getplayervel()
{
    return(vel);
}
//============================================
int Hero::getplayerdirection()
{
    return(direction);

}
//=============================================
void Hero::playerdying()    //falling
{
    float frameindex=0.08; //duration of time per frame
    if(alive==0)
        frameindex*=3;

    delta_t=last_time-GetTime();    //calc the time change since last loop
    frametimer+=delta_t;
    last_time=GetTime();            //mark the new start time

    if (frametimer>frameindex)
    {
        frame++;
        if (frame>3)
            frame=2;    //hold at the last frame
        frametimer=0;
        alive=0;

    }

    

    Rectangle source={0+512*(int)frame,512,512,512};
    Rectangle destin={pos.x,pos.y,512*scale,512*scale};

    DrawTexturePro(media::heroimage,source,destin,{0,0},0,WHITE);


}