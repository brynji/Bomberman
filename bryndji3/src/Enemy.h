#pragma once

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(int x, int y, int color, int health, int explosionSize, int maxBombs, int moveDelay, int bombDelay);
    bool input(int in, const uint64_t now, int& xOut, int& yOut) override;
};