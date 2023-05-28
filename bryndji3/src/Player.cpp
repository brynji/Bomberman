
#include "Player.h"

Player::Player(int x, int y, int color,int up, int down, int left, int right, int bomb): Character(x,y,color){
    keyUp=up;
    keyDown=down;
    keyLeft=left;
    keyRight=right;
    keyBomb=bomb;
}

bool Player::input(int in, int& xOut, int& yOut){
    if(in==keyBomb){
        xOut=-123;
        yOut=-123;
        return true;
    }
    
    if(!canMove){
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
    return true;
}