#pragma once

class Character {
public:
    
    virtual ~Character() = default;

    int x;
    int y;
    int offsetX;
    int offsetY;
    int health;
};