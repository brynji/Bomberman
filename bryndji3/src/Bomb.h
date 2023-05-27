#pragma once
#include "Map.h"

#define delay 1000

class Bomb {
    public:
    Bomb(int nX, int nY, int nExplosionSize, Map * nMap);

    bool operator() ();

    void Explode();

    void Clean();

    

    int x;
    int y;
    int explosionSize;
    uint64_t time;
    Map * map;

    bool exploded = false;
};