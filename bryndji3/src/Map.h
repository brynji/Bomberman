#pragma once
#include <string>
#include <vector>
#include <queue>

enum gameObject{
    wall,
    crate,
    powerup,
    bomb,
    empty
};

class Map{
    public:
    //Default constructor
    Map();

    //Load map from file 'file'
    Map(const std::string & file);

    //Acces map at[x,y]
    gameObject operator () (int x, int y);
    
    std::vector<gameObject> map;
    std::queue<std::pair<int,int>> refreshQueue;
    int sizeX;
    int sizeY;
};