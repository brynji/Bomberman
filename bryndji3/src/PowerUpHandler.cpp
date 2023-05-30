#include "PowerUpHandler.h"

#include "BiggerExplosion.h"
#include "FasterExplosion.h"
#include "MoreBombs.h"
#include "BonusHp.h"
#include "MovementSpeed.h"

void PowerUpHandler::addConfig(std::map<std::string,int> & config){
    powerUps.emplace_back(std::make_unique<BonusHp>(),config.find("bonusHp_chance")->second);
    powerUps.emplace_back(std::make_unique<BiggerExplosion>(),config.find("biggerExplosion_chance")->second);
    powerUps.emplace_back(std::make_unique<FasterExplosion>(),config.find("fasterExplosion_chance")->second);
    powerUps.emplace_back(std::make_unique<MoreBombs>(),config.find("moreBombs_chance")->second);
    powerUps.emplace_back(std::make_unique<MovementSpeed>(),config.find("movementSpeed_chance")->second);
}

//--------------------------------------------------------------------------------------------------

std::string PowerUpHandler::pickUp(Character & pl){
    int rnd=rand()%100;
    int num=0;
    for(uint i=0;i<powerUps.size();i++){
        num+=powerUps[i].second;
        if(rnd<num){
            return powerUps[i].first->pickUp(pl);
        }
    }
    return "";
}