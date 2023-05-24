#pragma once
#include <map>
#include <iostream>

class Loader {
    public:
    //Load config file, save all values into map given in second parameter
    void loadConfig(const std::string & configFile, std::map<std::string,int> & config);

    //Create vector of all powerUps
    bool loadPowerUps();
};