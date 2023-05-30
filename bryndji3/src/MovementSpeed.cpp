#include "MovementSpeed.h"

std::string MovementSpeed::pickUp(Character & pl){
    pl.moveDelay*=0.5;
    return "movement speed";
}