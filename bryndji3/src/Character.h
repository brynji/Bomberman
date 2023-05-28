#pragma once

class Character {
public:
    Character(int nX, int nY, int nColor);
    
    virtual ~Character() = default;

    virtual bool input(int in, int& xOut, int& yOut)=0;

    bool hit();

    int xPos;
    int yPos;
    int offsetX;
    int offsetY;

    int color;
    bool canMove = true;

    int health = 1;
    int explosionSize = 1;
    int maxBombs = 2;
    int currBombs = 0;
};