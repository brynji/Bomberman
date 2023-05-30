#include "BiggerExplosion.h"

std::string BiggerExplosion::pickUp(Character & pl)const{
    pl.explosionSize+=1;
    return "bigger explosion";
}
