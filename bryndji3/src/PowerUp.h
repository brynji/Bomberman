#pragma once

#include "Character.h"

///Abstract class for all powerUps
class PowerUp{
    public:
    virtual ~PowerUp()=default;

    virtual std::string pickUp (Character & pl)=0;
};