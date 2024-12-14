#include "insect.h"
#include <vector>
#include "swarm.h"
#include "media.h"


double insect::currtime{0}; //reserve space static variables
double insect::deltaT{0};
//=====================================================
//                      constructor
insect::insect()
{

    pos.x=GetRandomValue(1200,1500);  //generate random x,y position
    pos.y=GetRandomValue(900,900);

    // Site of the great uninitialized variable debacle
    // New procedure assures that there will be a valid velocity number
    vel.x=GetRandomValue(100,500);  
    vel.y=GetRandomValue(100,500);
    if ((GetRandomValue(0,100)>50)) vel.x*=-1;
    if ((GetRandomValue(0,100)>50)) vel.y*=-1;


    rotation=0;
    scale=GetRandomValue(1,3)*0.5f;   //random size
    spritecntr.x=(spritedimension/2*scale);
    spritecntr.y=(spritedimension/2*scale);
    spritedimension=128;


    //initial collision rect on creation
    colrec={pos.x-128/2*scale,pos.y=128/2*scale,128*scale,128*scale};



    last_time=GetTime();    //set the time stamp to birth
    frame=0;                //initial frame
    frametimer=0.0;
    vitality=Alive;
    alive=1;
    deathclock=0.2;     //timer for total countdown during death timing. 2 seconds
    colliding=false;
    frametimedeath=0;
    frame2=0;           //frame counter for death sequence

    

    

    return;
}
//=====================================================
//update pos of individual roach. 
//adjust rotation and check boundries

void insect::updateroachpos()
{
    double delta_t=GetTime()-last_time;
    if(delta_t>0.1) delta_t=0.1;

    frametimer+=delta_t; // keep track of time between steps
    
    if(vel.x!=0)
    {
        pos.x+=vel.x*delta_t;
        pos.y+=vel.y*delta_t;

        rotation=90+radians2degrees(atan2(vel.y,vel.x));
        last_time=GetTime(); //very important to update timestamp :|

        //bounds checking
        //----------------------
        if(pos.x<10)
        {
            pos.x+=2;
            vel.x*=-1;
        }
        if(pos.x>GetScreenWidth()-128)
        {
            pos.x-=2;
            vel.x*=-1;
        }
        if(pos.y<10)
        {
            pos.y+=2;
            vel.y*=-1;
        }
        if(pos.y>GetScreenHeight()-128)
        {
            pos.y-=2;
            vel.y*=-1;
        }

        
    //---------------------

        if(frametimer>=.05)
        {   
            frametimer=0;   //reset frame timer
            if(++frame>2)   //Increment and if past the last frame on the spritesheet
                frame=0;    //start at the first

        
        }

    }


    return;
}
//=====================================================

void insect::killroach()
{
    vitality=Dead;      //enumeration!
    vel={0,0};          //hold the roach still
    //pos={0,0};          //since collision uses the position to form a circle--zero it at death
    currtime=GetTime();
    frame=0;            //use frame to index the death animation

    return;
}
//=====================================================

void insect::drawroach()   //pass delta_time
{
    int framesperclock=6;
    
    //⁡⁣⁢⁣⁡⁣⁢⁣𝗧𝗵𝗲 𝗥𝗼𝗮𝗰𝗵 𝗶𝘀 𝗮𝗹𝗶𝘃𝗲 ⁡- Routine position update
    if(vitality==Alive)   //type enum life
    {
        //draws an individual roach and then again for the shadow if the roach is alive

        Rectangle source={(128.0f*frame),0,128.0f,128.0f};
        Rectangle dest={pos.x,pos.y,128*scale,128*scale};

        //shadow rectangle is offset from the original
        Rectangle dest2={pos.x+15,pos.y+15,128*scale,128*scale}; //shadow position
        Color shadow={0,0,0,128};  //128 of 255 in alpha channel-transparent

        // deprecated...now using circles for collisions--may eliminate
        colrec={pos.x-128/2*scale,pos.y-128/2*scale,128*scale,128*scale};

        //draw the shadow first and then roach on top of it
        DrawTexturePro(media::bug,source,dest2,spritecntr,rotation,shadow);
        DrawTexturePro(media::bug,source,dest,spritecntr,rotation,WHITE);

        
    }
    // ⁡⁣⁢⁣𝗧𝗵𝗲 𝗥𝗼𝗮𝗰𝗵 𝗶𝘀 𝗗𝗲𝗮𝗱--𝗗𝗲𝗮𝘁𝗵𝗰𝗹𝗼𝗰𝗸>𝟬 𝗔𝗻𝗶𝗺𝗮𝘁𝗶𝗼𝗻 𝗢𝗻𝗴𝗼𝗶𝗻𝗴⁡
    // visit the animation routine. Tick down the deathclock
    else if(vitality==Dead && deathclock>0)
    {
        float index=2.0f/6.0f;  //time to spend on each frame

        deltaT=GetTime()-currtime;
        deathclock=deathclock-deltaT; //decrement the animation time limit
        frametimedeath+=deltaT; //increment the frame timer

        if(frametimedeath>=index)
        {

            frame2++;    //increment to next animation frame
            frametimedeath=0;   //this counts the time for each splat animation frame


        }

        //do something

        


        
        
        Rectangle source={540*frame2,0,540,590};
        Rectangle dest={pos.x,pos.y,255*scale,255*scale};

        DrawTexturePro(media::splat,source,dest,{0,0},0.0f,WHITE);

        currtime=GetTime();
        //reset the currtime as we leave the loop
    }

    // ⁡⁣⁢⁣𝗧𝗵𝗲 𝗥𝗼𝗮𝗰𝗵 𝗶𝘀 𝗗𝗲𝗮𝗱- 𝗩𝗲𝗹𝗼𝗰𝗶𝘁𝘆 𝗶𝘀 𝗭𝗲𝗿𝗼 - 𝗗𝗲𝗮𝘁𝗵𝗰𝗹𝗼𝗰𝗸 𝗭𝗲𝗿𝗼- 𝘋𝘳𝘢𝘸 𝘴𝘵𝘢𝘵𝘪𝘰𝘯𝘢𝘳𝘺 𝘴𝘱𝘭𝘢𝘵⁡
    else
    {
        Rectangle source={540*frame2,0,540,590};
        Rectangle dest={pos.x,pos.y,255*scale,255*scale};
        DrawTexturePro(media::splat,source,dest,{0,0},0.0f,WHITE);
    }
    return;
}
//=====================================================
Vector2 insect::getbugpos()
     {
        
        return pos;
    }
//=====================================================

float insect::getbugscale()
{
    return scale;
}


//=====================================================

//=====================================================
//      utility for use with calculating roach rotation
//      from direction. (atan2 gives result in radians)
//      sprite rotation is in degrees


double insect::radians2degrees(double rads)
{
    return(rads*180.0f/M_PI);

}