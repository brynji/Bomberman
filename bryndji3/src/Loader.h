#pragma once
#include <map>
#include <vector>
#include <iostream>

#include "Map.h"

class Loader {
    public:

    template<typename T>
    bool load(std::map<std::string,T> & config, const std::string & target, const std::string & fileName);

    //Load config file, save all values into map given in second parameter
    bool loadConfig(std::map<std::string,int> & config);

    bool loadControls(std::map<std::string,char> & config);

    bool loadMaps(std::vector<Map> & vec);

    bool loadLeaderboard(std::vector<std::string> & vec);
};