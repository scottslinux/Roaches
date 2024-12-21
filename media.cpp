#include "media.h"
#include "raylib.h"

//  Initiaialize Static Variables to Zero State
Texture2D media::bug={0};
Texture2D media::splat={0};
Texture2D media::heroimage={0};
Texture2D media::sink={0};
Texture2D media::splash={0};
Texture2D media::garbage={0};
Font media::titlefont={0};

Music media::backgroundmusic={0};
Music media::splashmusic={0};
Sound media::lasershot={0};
Sound media::squish={0};
Sound media::scream={0};
 
//====================================

media::media(/* args */)    //constructor--not used STATIC Functions
{
}
//====================================
media::~media()
{
}
//====================================

void media::loadMediaFiles()    //static function (see .h)to load media
{
    //Load all of the image files into static variables
    bug=LoadTexture("resources/Roach sprites.png");
    splat=LoadTexture("resources/splat.png");
    heroimage=LoadTexture("resources/exterminator.png");
    sink=LoadTexture("resources/sink.png");
    splash=LoadTexture("resources/splash.png");
    garbage=LoadTexture("resources/garbage.png");

    titlefont=LoadFontEx("resources/Slimespooky.ttf",32,NULL,0);


        //Load all of the sound files into static variables
    backgroundmusic=LoadMusicStream("resources/bgsound.wav");
    splashmusic=LoadMusicStream("resources/splash.wav");

    lasershot=LoadSound("resources/Laser.wav");
    squish=LoadSound("resources/squish.wav");
    scream=LoadSound("resources/scream.wav");


    return;
}

//====================================

void media::unloadMediaFiles()
{
    // Free up all of the resources
    UnloadTexture(bug);
    UnloadTexture(splat);
    UnloadTexture(heroimage);
    UnloadTexture(sink);
    UnloadTexture(garbage);
    UnloadFont(titlefont);

    UnloadMusicStream(backgroundmusic);
    UnloadMusicStream(splashmusic);
    UnloadSound(lasershot);
    UnloadSound(scream);
    UnloadSound(squish);

    CloseAudioDevice();


    return;
}
