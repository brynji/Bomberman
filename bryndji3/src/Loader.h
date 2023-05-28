#pragma once
#include <map>
#include <iostream>

class Loader {
    public:

    template<typename T>
    bool load(std::map<std::string,T> & config, const std::string & target, const std::string & fileName);

    //Load config file, save all values into map given in second parameter
    bool loadConfig(std::map<std::string,int> & config);

    bool loadControls(std::map<std::string,char> & config);
};