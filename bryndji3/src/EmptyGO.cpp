#include "EmptyGO.h"

EmptyGO::EmptyGO(int colorPair, const std::array<std::string,3>& icon): GameObject(colorPair,icon) {}

void EmptyGO::hit(){}

bool EmptyGO::stepOn(){
    return true;
}