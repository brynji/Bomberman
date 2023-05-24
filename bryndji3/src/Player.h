#pragma once

#include "Character.h"

class Player : public Character {
public:
    Player(int x, int y): Character(x,y){}

    bool input(int in, int& xOut, int& yOut);

    int keyLeft = 'a';
    int keyRight = 'd';
    int keyUp = 'w';
    int keyDown = 's';
    int keyBomb = ' ';
};