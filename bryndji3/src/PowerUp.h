#pragma once

#include "Character.h"

class PowerUp{
    public:
    virtual ~PowerUp()=default;

    virtual void pickUp (Character & pl)=0;
};