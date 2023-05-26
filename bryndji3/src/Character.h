#pragma once

class Character {
public:
    Character(int nX, int nY, int nColor): xPos(nX), yPos(nY), color(nColor){}
    virtual ~Character() = default;

    int xPos;
    int yPos;
    int offsetX;
    int offsetY;

    int color;

    int health=1;
    int explosionSize = 2;
    int maxBombs = 1;
};