#pragma once

class Character {
public:
    Character(int nX, int nY, int nColor): xPos(nX), yPos(nY), color(nColor){}
    virtual ~Character() = default;

    int xPos;
    int yPos;
    int offsetX;
    int offsetY;
    int health;
    int color;
};