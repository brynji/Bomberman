#pragma once
#include "GameObject.h"

class Crate : public GameObject{
public:
    Crate(int colorPair=2, const std::array<std::string,3>& icon={"xxxxx","xxxxx","xxxxx"});

    //Called when hit by a bomb - do nothing, wall cannot be destroyed
    void hit()override;
    
    //Called when player tries to step on this gameObject, return value - false-> player can't step here. true-> player can step here
    bool stepOn()override;
};