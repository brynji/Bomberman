#pragma once
#include <vector>

#include "Map.h"

class Menu{
    public:

    //start main menu, return selected map, set start to true for the game to start or false to close it
    Map main(bool & start);

    //load all maps from path 'mapDir'
    bool loadMaps();

    const std::string mapDir = "examples/maps";
    std::vector<Map> maps;
};