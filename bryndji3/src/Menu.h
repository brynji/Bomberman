#pragma once
#include <vector>

#include "Map.h"

class Menu{
    public:

    int drawMenu(int x, int y, const std::vector<std::string> & options);

    //start main menu, return selected map, set start to true for the game to start or false to close it
    Map main(bool & start, int & numberOfPlayers, int & numberOfAi);

    //load all maps from path 'mapDir'
    bool loadMaps();

    const std::string mapDir = "examples/maps";
    std::vector<Map> maps;
};