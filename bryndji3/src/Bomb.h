#include "Map.h"

class Bomb {
    Bomb(int nX, int nY, int nExplosionSize, Map * nMap) : x(nX), y(nY), explosionSize(nExplosionSize), map(nMap){} 

    void Explode(){
        (*map)(x,y)=empty;
    }

    int x;
    int y;
    int explosionSize;

    Map * map;
};