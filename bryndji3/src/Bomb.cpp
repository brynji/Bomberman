#include "Bomb.h"

Bomb::Bomb(int nX, int nY, int nExplosionSize, int delay, Character * nPl, Map * nMap, const uint64_t & now) : x(nX), y(nY), explosionSize(nExplosionSize), pl(nPl), map(nMap){
    time = now + delay;
    pl->currBombs += 1;
}

//--------------------------------------------------------------------------------------------------

BombState Bomb::operator() (const uint64_t & now){
    if(bombState==exploded) bombState=explodedAndChecked;
    if(now>=time){
        if(bombState==explodedAndChecked){
            Clean();
            bombState=cleanedExplosion;
        } else {
            Explode();
            bombState=exploded;
            time = now+200;
            pl->currBombs -= 1;
        }
    }
    return bombState;
}

//--------------------------------------------------------------------------------------------------

bool Bomb::explosionBehaviour(int x, int y){
    if(x<0 || x>=map->sizeX || y<0 || y>=map->sizeY){
        return false;
    }
    gameObject go = (*map)(x,y);
    if(go==wall){
        return false;
    }
    map->drawQueue.push({x,y});
    if(go==crate){
        //add percent chance
        if((rand()%100)<=powerUpChance){
            (*map)(x,y)=powerup;
        } else {
            (*map)(x,y)=empty;
        }
        return false;
    } 
    else if(go!=powerup && go!=bomb){
        (*map)(x,y)=explosion;
    } 
    return true;
}

//--------------------------------------------------------------------------------------------------

void Bomb::ExplodeRec(int xAdd, int yAdd, int i, int depth){
    if(i==depth) return;
    if(explosionBehaviour(x+(xAdd*i),y+(yAdd*i))){
        ExplodeRec(xAdd,yAdd,i+1,depth);
    }
    return;
}

//--------------------------------------------------------------------------------------------------

void Bomb::Explode(){
    (*map)(x,y)=explosion;
    map->drawQueue.push({x,y});
    ExplodeRec(-1,0,1,explosionSize+1);
    ExplodeRec(1,0,1,explosionSize+1);
    ExplodeRec(0,-1,1,explosionSize+1);
    ExplodeRec(0,1,1,explosionSize+1);
}

//--------------------------------------------------------------------------------------------------

void Bomb::CleanRec(int xAdd, int yAdd, int i, int depth){
    int currX = x+(xAdd*i);
    int currY = y+(yAdd*i);
    if(i==depth || currX<0 || currX>=map->sizeX || currY<0 || currY>=map->sizeY) return;
    gameObject go = (*map)(currX,currY);
    if(go==explosion){
        (*map)(currX,currY)=empty;
        map->drawQueue.push({currX,currY});
        CleanRec(xAdd,yAdd,i+1,depth);
    } else if (go==powerup || go==bomb){
        CleanRec(xAdd,yAdd,i+1,depth);
    }
    return;
}

//--------------------------------------------------------------------------------------------------

void Bomb::Clean(){
    CleanRec(-1,0,0,explosionSize+1);
    CleanRec(1,0,1,explosionSize+1);
    CleanRec(0,-1,1,explosionSize+1);
    CleanRec(0,1,1,explosionSize+1);
}