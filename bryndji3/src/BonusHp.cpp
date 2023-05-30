#include "BonusHp.h"

std::string BonusHp::pickUp(Character & pl)const{
    pl.health+=1;
    return "bonus health";
}