#pragma once
#include <cstdint>

class Character {
public:
    Character(int nX, int nY, int nColor);
    
    virtual ~Character() = default;

    virtual bool input(int in, const uint64_t now, int& xOut, int& yOut)=0;

    bool hit();

    int xPos;
    int yPos;

    int color;

    int health = 1;
    int explosionSize = 1;
    int maxBombs = 2;
    int moveDelay = 150; 
    int bombDelay = 2000;
    
    int currBombs = 0;
    uint64_t moveTime = 0;
};