#include <filesystem>
#include <iostream>
#include <ncurses.h>

#include "Menu.h"

Map Menu::main(bool & start){
    if(!loadMaps()){
        start=false;
        return Map();
    }
    


    start=true;
    return maps.at(0);
}

bool Menu::loadMaps(){
    try{
        const std::filesystem::path dir (mapDir);  
        for(const auto & x : std::filesystem::directory_iterator(dir)){
            maps.emplace_back(Map(x.path()));
            if(maps.back().sizeX<=0 || maps.back().sizeY<=0 || maps.back().playerSpawnPositions.size()<4){
                std::cout<<"Map \""<<x<<"\" has incorrect size or less than 4 player spawn positions.\nPress Enter to continue."<<std::endl;
                std::getchar();
                maps.pop_back();
            }
        }
    } catch (...){
        std::cout<<"Path \"examples/maps\" does not exist."<<std::endl;
        return false;
    }
    if(maps.size()<1){
        std::cout<<"No maps loaded."<<std::endl;
        return false;
    }
    return true;
}