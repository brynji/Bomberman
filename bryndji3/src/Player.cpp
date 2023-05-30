
#include "Player.h"

Player::Player(int x, int y, int color,int up, int down, int left, int right, int bomb, int health, int explosionSize, int maxBombs, int moveDelay, int bombDelay, const std::string & name): 
    Character(x,y,color,health,explosionSize,maxBombs,moveDelay,bombDelay,name){
    keyUp=up;
    keyDown=down;
    keyLeft=left;
    keyRight=right;
    keyBomb=bomb;
}

//--------------------------------------------------------------------------------------------------

bool Player::input(int in, const uint64_t now, int& xOut, int& yOut){
    if(in==keyBomb){
        xOut=-123;
        yOut=-123;
        return true;
    }
    
    if(moveTime>now){
        return false;
    }

    if(in==keyUp){
        xOut=xPos;
        yOut=yPos-1;
    } else if(in==keyDown){
        xOut=xPos;
        yOut=yPos+1;
    } else if(in==keyLeft){
        xOut=xPos-1;
        yOut=yPos;
    } else if(in==keyRight){
        xOut=xPos+1;
        yOut=yPos;
    } else {
        return false;
    }
    moveTime=now+moveDelay;
    return true;
}