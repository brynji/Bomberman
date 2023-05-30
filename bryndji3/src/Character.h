#pragma once

#include <cstdint>
#include <string>

class Character {
public:
    Character(int nX, int nY, int nColor, int nHealth, int nExplosionSize, int nMaxBombs, int nMoveDelay, int nBombDelay, const std::string & nName);
    
    virtual ~Character() = default;

    virtual bool input(int in, const uint64_t now, int& xOut, int& yOut)=0;

    bool hit();

    int xPos;
    int yPos;

    int color;
    const std::string name;

    int health;
    int explosionSize;
    int maxBombs;
    int moveDelay; 
    int bombDelay;
    
    int currBombs = 0;
    uint64_t moveTime = 0;
};