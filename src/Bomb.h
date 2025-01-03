#pragma once
#include "Map.h"
#include "Character.h"

#define powerUpChance 40

enum BombState {placed,exploded,explodedAndChecked,cleanedExplosion};


class Bomb {
public:
    Bomb(int nX, int nY, int nExplosionSize, int delay, Character * nPl, Map * nMap, const uint64_t & now);

    BombState operator() (const uint64_t & now);

private:
    bool explosionBehaviour(int x, int y);
    void ExplodeRec(int xAdd, int yAdd, int i, int depth);
    void Explode();

    void CleanRec(int xAdd, int yAdd, int i, int depth);
    void Clean();

    int x;
    int y;
    int explosionSize;
    uint64_t time;
    Character * pl;
    Map * map;

    BombState bombState = placed;
};