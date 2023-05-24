#include <filesystem>

#include "Menu.h"

Map Menu::main(bool & start){
    loadMaps();
    
    start=true;
    return maps.at(0);
}

void Menu::loadMaps(){
    const std::filesystem::path dir (mapDir);   
    for(const auto & x : std::filesystem::directory_iterator(dir)){
        maps.emplace_back(Map(x.path()));
    }
}