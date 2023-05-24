#pragma once
#include <iostream>
#include <map>

#include "Map.h"
#include "Player.h"

class GameMaster{
    public:
    //Start game - load config, load powerups, go to main menu, quit or start a new game
    void start();

    //Main game loop - read input, move players, refresh screen
    void mainLoop();

    //Close game and clean screen
    void closeGame();

    const std::string configFile = "examples/config";   //Config file path
    std::map<std::string,int> config;   //Loaded config file
    Map map;    //Current map
    std::vector<Player> players;
};