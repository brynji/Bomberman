#pragma once

#include "Player.h"

class PowerUp {
    public:
    PowerUp(Player & nPl);

    virtual void pickUp()=0;

    Player pl;
};