#pragma once

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "Character.h"
#include "PowerUp.h"

///Chooses which powerUps should be picked up
class PowerUpHandler {
public:
    /**
     * Reads settings from configuration file and uses them
     * @param config map with settins
     */
    void addConfig(std::map<std::string,int> & config);

    /**
     * Called when player picks up powerUp, randomly chooses one and applies it
     * @param pl Player who should receive the powerUp
     * @return name of the powerUp for UI to print
     */
    std::string pickUp(Character & pl)const;
private:
    ///Vector with instances of every powerUp and their % chance of getting picked up
    std::vector<std::pair<std::unique_ptr<PowerUp>,int>> powerUps;
};