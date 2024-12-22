#pragma once

#include <iostream>
#include "raylib.h"



class media
{

public:

    static Texture2D bug;
    static Texture2D splat;
    static Texture2D heroimage;
    static Texture2D sink;
    static Texture2D splash;
    static Texture2D garbage;
    static Font titlefont;


    static Sound lasershot;
    static Sound squish;
    static Sound scream;
    static Sound scorebell;

    static Music backgroundmusic;
    static Music splashmusic;



    media(/* args */);
    ~media();

    static void loadMediaFiles();
    static void unloadMediaFiles();

};


