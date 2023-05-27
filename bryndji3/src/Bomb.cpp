#include "Bomb.h"

#include <chrono>

Bomb::Bomb(int nX, int nY, int nExplosionSize, Map * nMap) : x(nX), y(nY), explosionSize(nExplosionSize), map(nMap){
    time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() + delay;
}

bool Bomb::operator() (){
    uint64_t now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    if(now>=time){
        if(exploded){
            Clean();
            return true;
        } else {
            Explode();
            exploded=true;
            time = now+200;
        }
    }
    return false;
}


void Bomb::Explode(){
        (*map)(x,y)=empty;
        map->drawQueue.push({x,y});
    }

void Bomb::Clean(){

}