#pragma once

#include "Character.h"

class PowerUp{
    public:
    virtual ~PowerUp()=default;

    virtual std::string pickUp (Character & pl)=0;
};