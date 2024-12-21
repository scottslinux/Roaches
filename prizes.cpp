#include"prizes.h"

#include<iostream>
#include<vector>
#include "raylib.h"
#include "media.h"
#include "Hero.h"
#include "levelManager.h"


prizes::prizes()
{
    pos.x=GetRandomValue(0,GetScreenWidth());
    pos.y=GetRandomValue(0,GetScreenHeight());
    scale=0.40f;
    prizevalue=GetRandomValue(50,500);
    int frame2=(int)(GetRandomValue(0,3));
    
    
    caught=false;
    display=true;


    bool caught;
    bool display;




}

void prizes::displayprizes()
{
    Rectangle source={0,512*frame2,512,512};
    Rectangle dest={pos.x,pos.y,512*scale,512*scale};

    DrawTexturePro(media::garbage,source,dest,{0,0},0,WHITE);
std::cout<<frame2<<std::endl;


    return;
}