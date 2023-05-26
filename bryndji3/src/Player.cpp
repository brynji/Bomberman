
#include "Player.h"

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