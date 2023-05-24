#pragma once

class Character {
public:
    Character(int nX, int nY): x(nX), y(nY){}
    virtual ~Character() = default;

    int x;
    int y;
    int offsetX;
    int offsetY;
    int health;
};