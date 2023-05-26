#pragma once

#include "Character.h"

class PowerUp {
    public:
    virtual void pickUp(Character & pl)=0;
};