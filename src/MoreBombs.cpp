#include "MoreBombs.h"

std::string MoreBombs::pickUp(Character & pl)const{
    pl.maxBombs+=1;
    return "more bombs";
}