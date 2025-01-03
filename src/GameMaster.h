#pragma once

#include <iostream>
#include <map>
#include <memory>

#include "Map.h"
#include "UI.h"
#include "Character.h"
#include "Player.h"
#include "Bomb.h"
#include "PowerUpHandler.h"

class GameMaster{
public:
    //Start game - load config, load powerups, go to main menu, quit or start a new game
    void start();

private:
    //Main game loop - read input, move players, refresh screen
    void mainLoop();

    void reset();

    //Close game and clean screen
    void closeGame();

    void moveCharacter(int x, int y, Character & pl, UI & ui);

    std::map<std::string,int> config;   //Loaded config file
    std::map<std::string,char> controls;   //Loaded controls file
    Map map;    //Current map
    PowerUpHandler powerUpHandler;
    std::vector<std::unique_ptr<Character>> players;
    std::vector<Bomb> bombs;     //Bombs placed on the map
    uint64_t timeNow;
};