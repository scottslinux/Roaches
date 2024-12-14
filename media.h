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


    static Sound lasershot;
    static Sound squish;

    static Music backgroundmusic;



    media(/* args */);
    ~media();

    static void loadMediaFiles();
    static void unloadMediaFiles();

};


