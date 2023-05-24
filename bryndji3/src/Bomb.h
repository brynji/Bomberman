#pragma once
#include "GameObject.h"


class Bomb: public GameObject{
    public:

    //Constructor takes 2 parameters - coordinas the bomb was placed on
    Bomb(int colorPair, const std::array<std::string,3>& icon, int nExplosionSize);

    //Called when another bomb explosion hits this bomb - this bomb should then explode too
    void hit()override;

     //Called when player tries to step on this gameObject, return value - false-> player can't step here. true-> player can step here
    bool stepOn()override;

    //Explode
    void explode();


    int explosionSize;
    bool exploded=false;
};