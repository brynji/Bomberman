#pragma once

#include <vector>

#include "Map.h"
#include "Loader.h"

/**
 * Creates main menu, shows leaderboard and allows player to choose number of players and ai opponents
 */
class Menu{
    public:

    /**
     * Start main menu
     * @param start output bool signalizing if game should start or end
     * @param numberOfPlayers numbers of real players user has chosen
     * @param numberOfAi number of ai players user has chosen
     * @param names names of real players
     * @return map that should be played
     */
    Map main(bool & start, int & numberOfPlayers, int & numberOfAi, std::vector<std::string> & names);

private:
    /**
     * Draws options from options to the screen, lets user pick what he wants
     * @param x starting coordinate of the text
     * @param y starting coordinate of the test
     * @param options vector of options user can choose from
     * @return position of selected option in the options vector
     */
    int drawMenu(int x, int y, const std::vector<std::string> & options);

    /**
     * Shows leaderboard
     */
    void showLeaderboard();

    /**
     * Loads all maps from maps folder
     * @return bool signalizing error while loading
     */
    bool loadMaps();

    ///vector containing all loaded maps
    std::vector<Map> maps;
    ///Instance of loader, used to load maps and leaderboard
    Loader loader;
};