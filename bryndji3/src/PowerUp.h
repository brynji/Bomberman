#pragma once

#include "Character.h"

///Abstract class for all powerUps
class PowerUp{
public:
    ///Virtual destructor
    virtual ~PowerUp()=default;
    /**
     * Virtual method for all powerUps, called when player picksUp powerUp
     * @param pl player who picked up powerUp
     * @return name of the powerUp for UI to draw
     */
    virtual std::string pickUp (Character & pl)=0;
};