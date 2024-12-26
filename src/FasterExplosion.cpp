#include "FasterExplosion.h"

std::string FasterExplosion::pickUp(Character & pl)const{
    pl.bombDelay*=0.8;
    return "faster explosion";
}