#pragma once
#include <iostream>
#include <map>

#include "Map.h"
#include "UI.h"
#include "Character.h"
#include "Player.h"

class GameMaster{
    public:
    //Start game - load config, load powerups, go to main menu, quit or start a new game
    void start();

    //Main game loop - read input, move players, refresh screen
    void mainLoop();

    //Close game and clean screen
    void closeGame();

    void moveCharacter(int x, int y, Character & pl, UI ui);
    
    void getPowerUp(Character & pl);

    const std::string configFile = "examples/config";   //Config file path
    std::map<std::string,int> config;   //Loaded config file
    Map map;    //Current map
    std::vector<Player> players;
};