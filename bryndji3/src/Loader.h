#pragma once

#include <map>
#include <vector>
#include <iostream>

#include "Map.h"

/**
 * Used for loading configurationi file, controls file, maps and  loading and updating leaderboard
 */
class Loader {
public:

    /**
     * Load configuration file
     * @param config map to save loaded data to
     * @return true if data were successfully loaded and saved, false otherwise
     */
    bool loadConfig(std::map<std::string,int> & config);

    /**
     * Loads controls file
     * @param config map to save loaded data to
     * @return true if data were successfully loaded and saved, false otherwise
     */
    bool loadControls(std::map<std::string,char> & config);

    /**
     * Loads maps and saves them into the vector
     * @param vec vector to save loaded data to
     * @return true if data were successfully loaded and saved, false otherwise
     */
    bool loadMaps(std::vector<Map> & vec);

    /**
     * Loads leaderboard, saves names into the vector
     * @param vec vector to save names to
     * @return true if data were successfully loaded and saved, false otherwise
     */
    bool loadLeaderboard(std::vector<std::string> & vec);

    /**
     * Adds new name into the leaderboard
     * @param name new name that should be saved
     */
    void updateLeaderboard(std::string name);

private:
    /**
     * Loads file 'target', saves data of type T into the map
     * @tparam T Type of data that will be loaded from file and saved into the map
     * @param config map where data will be saved
     * @param target path to the file that should be loaded
     * @param fileName name of the file, used for printing errors with right file name
     * @return true if data were successfully loaded and saved, false otherwise
     */
    template<typename T>
    bool load(std::map<std::string,T> & config, const std::string & target, const std::string & fileName);

    const std::string leaderboardPath = "examples/.leaderboard";

    const std::string mapPath = "examples/maps";

    const std::string configPath = "examples/config";

    const std::string controlsPath = "examples/controls";
};
