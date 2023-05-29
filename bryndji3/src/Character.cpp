#include "Character.h"

Character::Character(int nX, int nY, int nColor, int nHealth, int nExplosionSize, int nMaxBombs, int nMoveDelay, int nBombDelay): 
    xPos(nX), yPos(nY), color(nColor), health(nHealth), explosionSize(nExplosionSize), maxBombs(nMaxBombs), moveDelay(nMoveDelay), bombDelay(nBombDelay) {}

bool Character::hit(){
    health-=1;
    return health<=0;
}