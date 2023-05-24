
#include "Player.h"

bool Player::input(int in, int& xOut, int& yOut){
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
    } else if(in==keyBomb){
        //Place bomb
    } else {
        return false;
    }
    return true;
}