#pragma once

#include <string>
#include <vector>
#include <queue>

/**
 * GameObject that can be on the map
 */
enum gameObject{
    wall,
    crate,
    bomb,
    powerup,
    empty,
    explosion
};

/**
 * Object representing game board
 */
class Map{
public:
    ///Default constructor
    Map();

    /**
     * Creates map from file file
     * @param file file containing map
     */
    Map(const std::string & file);

    /**
     * used to acces map at [x,y]
     * @param x row
     * @param y column
     * @return reference of gameobject on [x,y]
     */
    gameObject & operator () (int x, int y);

    ///Vector of gameobjects representing map
    std::vector<gameObject> map;
    ///Queue of positions players can start on
    std::queue<std::pair<int,int>> playerSpawnPositions;
    ///Queue of map positions that needs to be updated on the screen
    std::queue<std::pair<int,int>> drawQueue;
    ///number of columns
    int sizeX=0;
    ///number of rows
    int sizeY=0;
};