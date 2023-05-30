#include "BiggerExplosion.h"

std::string BiggerExplosion::pickUp(Character & pl){
    pl.explosionSize+=1;
    return "bigger explosion";
}
