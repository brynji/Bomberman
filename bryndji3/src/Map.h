#pragma once
#include <string>
#include <vector>
#include <queue>

enum gameObject{
    wall,
    crate,
    bomb,
    powerup,
    empty,
    explosion
};

class Map{
    public:
    //Default constructor
    Map();

    //Load map from file 'file'
    Map(const std::string & file);

    //Acces map at[x,y]
    gameObject & operator () (int x, int y);
    
    std::vector<gameObject> map;
    std::queue<std::pair<int,int>> playerSpawnPositions;
    std::queue<std::pair<int,int>> drawQueue;
    int sizeX=0;
    int sizeY=0;
};