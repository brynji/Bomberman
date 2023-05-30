#include "FasterExplosion.h"

std::string FasterExplosion::pickUp(Character & pl){
    pl.bombDelay*=0.8;
    return "faster explosion";
}