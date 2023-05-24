#pragma once

#include "GameObject.h"

class PowerUp : public GameObject {
    public:

    //Called when hit by bomb - does nothing
    void hit(){}

    //Called when player picks up powerUp, grant bonus to player
    virtual void pickUp()=0;

};