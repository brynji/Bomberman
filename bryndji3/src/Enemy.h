#pragma once

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(int x, int y, int color): Character(x,y,color){}

    bool input(int in, int& xOut, int& yOut) override;
};