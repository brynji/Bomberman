#include "MoreBombs.h"

std::string MoreBombs::pickUp(Character & pl){
    pl.maxBombs+=1;
    return "more bombs";
}