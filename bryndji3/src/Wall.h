#pragma once
#include "GameObject.h"

class Wall : public GameObject{
public:
    Wall(int colorPair=1, const std::array<std::string,3>& icon={"     ","     ","     "});

    //Called when hit by a bomb - do nothing, wall cannot be destroyed
    void hit()override;
    
    //Called when player tries to step on this gameObject, return value - false-> player can't step here. true-> player can step here
    bool stepOn()override;
};