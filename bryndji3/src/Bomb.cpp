#include "Bomb.h"

Bomb::Bomb(int colorPair, const std::array<std::string,3>& icon, int nExplosionSize): GameObject(colorPair,icon), explosionSize(nExplosionSize){}

void Bomb::hit() {
    explode();
}

bool Bomb::stepOn(){
    return false;
}

void Bomb::explode(){
    //call hit() on coords
    exploded=true;
}