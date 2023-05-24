#include "Crate.h"

Crate::Crate(int colorPair, const std::array<std::string,3>& icon): GameObject(colorPair,icon) {}

void Crate::hit(){
    //rozbij se
}

bool Crate::stepOn(){
    return false;
}