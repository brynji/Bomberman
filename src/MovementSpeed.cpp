#include "MovementSpeed.h"

std::string MovementSpeed::pickUp(Character & pl)const{
    pl.moveDelay*=0.85;
    return "movement speed";
}