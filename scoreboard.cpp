#include "scoreboard.h"
#include "media.h"
#include "levelManager.h"


//===================================================
scoreboard::scoreboard()    //constructor
{
    
    playerhealth=100;
    

    //only load the font once




}
//===================================================
void scoreboard::drawscreenframe()
{
    //  Routine to draw the background and the titles/score and graph

    //DrawTexture(media::sink,0,0,WHITE);
    Rectangle source={0,0,media::sink.width,media::sink.height};
    Rectangle dest={0,0,GetMonitorWidth(0),GetMonitorHeight(0)};

    DrawTexturePro(media::sink,source,dest,{0,0},0,WHITE);

    DrawRectangleGradientV(0,0,GetScreenWidth(),250,GREEN,DARKGREEN);
    DrawTextEx(media::titlefont,"INFESTATION",{1020,45},150,5,Color{0,0,0,128});  //blackshaddow
    DrawTextEx(media::titlefont,"INFESTATION",{1000,50},150,5,YELLOW);


    //    ⁡⁣⁢⁣𝗗𝗥𝗔𝗪 𝗧𝗛𝗘 𝗣𝗟𝗔𝗬𝗘𝗥 𝗟𝗜𝗩𝗘𝗦 𝗦𝗜𝗟𝗢𝗨𝗘𝗧𝗧𝗘𝗦⁡
    Rectangle sourcerec={0,0,512,512};
    Rectangle destin={2300,50,200,200};
    Color tint={25,25,25,128};     //set the color for the silouette
    for(int i=1;i<=levelManager::playerlives;i++)
    {//levelManager::playerlives
        destin.x=2000+i*120;
        DrawTexturePro(media::heroimage,sourcerec,destin,{0.0,0.0},0,tint);
    }

    int laser=missile::getremainlaser();
    std::stringstream ss;
    ss<<"Laser Remaining:  "<<laser;

    std::string mystring=ss.str();
    DrawText(mystring.c_str(),50,50,50,MAGENTA);


    Rectangle recEmpty={100,100,250,100};

    Rectangle recFull={100,100,laser,100};




    DrawRectangle(recEmpty.x,recEmpty.y,recEmpty.width,recEmpty.height,WHITE);

    DrawRectangle(recFull.x,recFull.y,recFull.width,recFull.height,RED);

    





    

}
//===================================================
void scoreboard::updateScore(int scorechange)
{
    
}
//===================================================
void scoreboard::killplayer()
{
    --playerlives;

}
//===================================================
