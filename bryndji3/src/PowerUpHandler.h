#pragma once

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "Character.h"
#include "PowerUp.h"

class PowerUpHandler {
    public:
    void addConfig(std::map<std::string,int> & config);

    void pickUp(Character & pl);

    std::vector<std::pair<std::unique_ptr<PowerUp>,int>> powerUps;
};