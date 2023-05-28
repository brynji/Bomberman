#include <fstream>

#include "Map.h"


Map::Map(){
    sizeX=0;
    sizeY=0;
}

Map::Map(const std::string & file){
    std::ifstream mapF(file);
    if(!mapF.good()){
        throw std::logic_error("Error opening map");
    }

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
                if(*ch=='P'){
                    playerSpawnPositions.emplace(j,i);
                }
            }
            ch++;
        }
    }
}

gameObject & Map::operator () (int x, int y){
    return map.at((y*sizeX)+x);
}