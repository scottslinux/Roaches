#include "garbage.h"
#include <iostream>
#include <vector>
#include "raylib.h"
#include "media.h"
#include "Hero.h"
#include "levelManager.h"

//using an initializer list to set only the necessary values
food::food()
    : pos{static_cast<float>(GetRandomValue(0, GetScreenWidth())),static_cast<float>(GetRandomValue(200, GetScreenHeight()))},
      rotation(static_cast<float>(GetRandomValue(0, 360))),
      prizevalue(GetRandomValue(50, 500)),
      frame(GetRandomValue(0, 3)),
      origin{512 * scale / 2, 512 * scale / 2} {
    // Constructor body (if needed)
}





//=====================================================

garbage::garbage(int num)
{
    //create a vector of food items while they rot...
    itemsinGarbage=num;  //ho

    //std::vector<food> prizes;

    prizes.resize(num);
}
//=====================================================
void garbage::displayGarbage()
{
    for(int i=0;i<itemsinGarbage;i++)
    {
        if(prizes[i].caught==false) //only display if not caught
        {
            Rectangle source={0,512*prizes[i].frame,512,512};
            Rectangle destin={prizes[i].pos.x,prizes[i].pos.y,512*prizes[i].scale,512*prizes[i].scale};
            Vector2 center={prizes[i].pos.x, prizes[i].pos.y};

            DrawTexturePro(media::garbage,source,destin,prizes[i].origin,0,WHITE);

        }
        


    }



}