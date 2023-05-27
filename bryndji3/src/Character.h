#pragma once

class Character {
public:
    Character(int nX, int nY, int nColor): xPos(nX), yPos(nY), color(nColor){}
    
    virtual ~Character() = default;

    virtual bool input(int in, int& xOut, int& yOut)=0;

    bool hit(){
        health-=1;
        return health<=0;
    }

    int xPos;
    int yPos;
    int offsetX;
    int offsetY;

    int color;
    bool canMove = true;

    int health = 1;
    int explosionSize = 2;
    int maxBombs = 2;
    int currBombs = 0;
};