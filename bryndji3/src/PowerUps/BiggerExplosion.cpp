#include "BiggerExplosion.h"

BiggerExplosion::BiggerExplosion(Player & nPl) : PowerUp(nPl) {}

void BiggerExplosion::pickUp(){
    pl.explosionSize+=1;
}
