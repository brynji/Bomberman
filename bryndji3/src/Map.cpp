#include <fstream>

#include "Map.h"
#include "Crate.h"
#include "Wall.h"
#include "EmptyGO.h"


Map::Map(){
    sizeX=0;
    sizeY=0;
}

Map::Map(const std::string & file){
    std::ifstream mapF(file);
    if(!mapF.good()){
        throw std::logic_error("Error opening map");
    }

    auto empty = std::make_shared<EmptyGO>();
    auto wall = std::make_shared<Wall>();
    auto crate = std::make_shared<Crate>();

    mapF>>sizeY>>sizeX;
    std::string line1;
    std::getline(mapF,line1);

    for(int i=0;i<sizeY;i++){
        std::string line;
        std::getline(mapF,line);
        auto ch = line.begin();
        for(int j=0;j<sizeX;j++){
            if(ch==line.end() || *ch=='\n'){
                map.push_back(empty);
                continue;
            } else if(*ch=='x'){
                map.push_back(wall);
            } else if(*ch=='c'){
                map.push_back(crate);
            } else {
                map.push_back(empty);
            }
            ch++;
        }
    }
}

std::shared_ptr<GameObject> Map::operator () (int x, int y){
    return map.at((x*sizeX)+y);
}