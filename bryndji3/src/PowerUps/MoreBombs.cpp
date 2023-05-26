#include "MoreBombs.h"

MoreBombs::MoreBombs(Player & nPl) : PowerUp(nPl) {}

void MoreBombs::pickUp(){
    pl.maxBombs+=1;
}