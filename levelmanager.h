#pragma once

#include <iostream>
#include "raylib.h"
#include "swarm.h"
#include "insect.h"
#include "Hero.h"

//  ​‌‌‍‍⁡⁣⁢⁣‍𝕃𝕖𝕧𝕖𝕝 𝕒𝕟𝕕 𝔾𝕒𝕞𝕖 𝕊𝕥𝕒𝕥𝕖 𝕄𝕒𝕟𝕒𝕘𝕖𝕣⁡​ 




class levelmanager
{

public:

    int currentLevel;
    int lives;
    int gameState;


    levelmanager(/* args */);
    void splashScreen();
    


};



