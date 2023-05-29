#include "Enemy.h"

Enemy::Enemy(int x, int y, int color, int health, int explosionSize, int maxBombs, int moveDelay, int bombDelay): Character(x,y,color,health,explosionSize,maxBombs,moveDelay,bombDelay){}

bool Enemy::input(int in,const uint64_t now, int& xOut, int& yOut){
    return false;
}