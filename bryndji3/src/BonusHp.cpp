#include "BonusHp.h"

std::string BonusHp::pickUp(Character & pl){
    pl.health+=1;
    return "bonus health";
}