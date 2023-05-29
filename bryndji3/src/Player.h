#pragma once

#include "Character.h"

class Player : public Character {
public:
    Player(int x, int y, int color,int up, int down, int left, int right, int bomb);

    bool input(int in, const uint64_t now, int& xOut, int& yOut) override;

    int keyLeft;
    int keyRight;
    int keyUp;
    int keyDown;
    int keyBomb;
};