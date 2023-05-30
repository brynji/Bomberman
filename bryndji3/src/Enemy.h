#pragma once

#include <vector>
#include <memory>

#include "Character.h"
#include "Map.h"

struct Point{
    Point(){}
    Point(int nX, int nY,int lX=0, int lY=0): lastPoint({lX,lY}) { x=nX; y=nY; }
    int x;
    int y;
    std::pair<int,int> lastPoint;
    bool operator < (const Point & X)const{
        if(x!=X.x) return x<X.x;
        else return y<X.y;
    }
};

class Enemy : public Character {
public:
    Enemy(int x, int y, int color, int health, int explosionSize, int maxBombs, int moveDelay, int bombDelay, Map * nMap,std::vector<std::unique_ptr<Character>> * nPlayers);

    bool input(int in, const uint64_t now, int& xOut, int& yOut) override;

    private:
    bool findPath (std::vector<Point> & path,gameObject destination,int xDest=-1, int yDest=-1);

    bool inDangerRec(int x, int y,int xAdd, int yAdd, int i);

    bool inDanger(int x, int y, int & xOut, int & yOut);

    void runFrom(int x, int y, int & xOut, int & yOut);

    bool canMoveOn(int x, int y, gameObject go=empty);

    bool isValid(int x, int y);

    Map * map;
    std::vector<std::unique_ptr<Character>> * players;
    bool targetPlayer = false;
    int bombsUntilTargetSwitch=3;
};