#include "Wall.h"

Wall::Wall(int colorPair, const std::array<std::string,3>& icon): GameObject(colorPair,icon) {}

void Wall::hit(){
}

bool Wall::stepOn(){
    return false;
}