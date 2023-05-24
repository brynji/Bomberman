#pragma once
#include <string>
#include <vector>
#include <queue>
#include <memory>

#include "GameObject.h"

class Map{
    public:
    //Default constructor
    Map();

    //Load map from file 'file'
    Map(const std::string & file);

    //Acces map at[x,y]
    std::shared_ptr<GameObject> operator () (int x, int y);
    
    std::vector<std::shared_ptr<GameObject>> map;
    std::queue<std::pair<int,int>> refreshQueue;
    int sizeX;
    int sizeY;
};