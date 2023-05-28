#include "Character.h"

Character::Character(int nX, int nY, int nColor): xPos(nX), yPos(nY), color(nColor){}

bool Character::hit(){
        health-=1;
        return health<=0;
    }