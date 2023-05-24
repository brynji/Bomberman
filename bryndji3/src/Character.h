#pragma once

class Character {
public:
    Character(int nX, int nY): xPos(nX), yPos(nY){}
    virtual ~Character() = default;

    int xPos;
    int yPos;
    int offsetX;
    int offsetY;
    int health;
};