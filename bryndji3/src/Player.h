#pragma once

#include "Character.h"

class Player : public Character {
public:
    Player(int x, int y, int color): Character(x,y,color){}

    bool input(int in, int& xOut, int& yOut);

    int keyLeft = 'a';
    int keyRight = 'd';
    int keyUp = 'w';
    int keyDown = 's';
    int keyBomb = ' ';
};