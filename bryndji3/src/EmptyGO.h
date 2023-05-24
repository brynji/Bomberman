#pragma once
#include "GameObject.h"

class EmptyGO : public GameObject{
public:
    EmptyGO(int colorPair=0, const std::array<std::string,3>& icon={"","",""});

    //Called when hit by a bomb - do nothing
    void hit()override;
    
    //Called when player tries to step on this gameObject, return value - false-> player can't step here. true-> player can step here
    bool stepOn()override;
};