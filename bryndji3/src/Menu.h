#pragma once
#include <vector>

#include "Map.h"
#include "Loader.h"

class Menu{
    public:

    int drawMenu(int x, int y, const std::vector<std::string> & options);

    void showLeaderboard();

    //start main menu, return selected map, set start to true for the game to start or false to close it
    Map main(bool & start, int & numberOfPlayers, int & numberOfAi, std::vector<std::string> & names);

    //load all maps from path 'mapDir'
    bool loadMaps();

    std::vector<Map> maps;
    Loader loader;
};