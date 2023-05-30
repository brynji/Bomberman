#include <set>

#include "Enemy.h"

Enemy::Enemy(int x, int y, int color, int health, int explosionSize, int maxBombs, int moveDelay, int bombDelay, Map * nMap,std::vector<std::unique_ptr<Character>> * nPlayers):
    Character(x,y,color,health,explosionSize,maxBombs,moveDelay,bombDelay,"Player"), map(nMap), players(nPlayers){}


bool Enemy::input(int in,const uint64_t now, int & xOut, int & yOut){
    if(moveTime>now){
        return false;
    }
    Point path;
    if(findPath(path,powerup)){
        xOut=path.x;
        yOut=path.y;
        moveTime=now+moveDelay;
        return true;
    }

    return false;
}

bool Enemy::isValid(int x, int y){
    if(x<0 || x>=map->sizeX || y<0 || y>=map->sizeY){
        return false;
    }
    return true;
}

bool Enemy::canMoveOn(int x, int y, gameObject){
    return (isValid(x,y) && ((*map)(x,y)==empty || (*map)(x,y)==powerup));
}

bool Enemy::findPath (Point & path, gameObject destination){
    std::queue<Point> q;
    std::set<Point> visited;

    int xAdd[] = {-1, 0, 0, 1};
    int yAdd[] = {0, -1, 1, 0};

    Point start (xPos,yPos,xPos,yPos);
    visited.insert(start);
    q.push(start);
    bool found=false;
    while(!q.empty()){
        Point curr = q.front();
        if((*map)(curr.x,curr.y)==destination){
            found=true;
            break;
        }
        for(int i=0;i<4;i++){
            int x = curr.x+xAdd[i];
            int y = curr.y+yAdd[i];
            if(canMoveOn(x,y) && visited.find(Point(x,y))==visited.end()){
                visited.insert(Point(x,y,curr.x,curr.y));
                q.push(Point(x,y,curr.x,curr.y));
            }
        }
        q.pop();
    }
    if(!found){
        return false;
    }
    Point curr = q.front();
    std::pair<int,int> startPos(xPos,yPos);
    while(curr.lastPoint!=startPos){
        curr = *visited.find(Point(curr.lastPoint.first,curr.lastPoint.second));
    }
    path=curr;
    return true;
}


























bool Enemy::inDangerRec(int x, int y,int xAdd, int yAdd, int i){
    if(i>=4 || !isValid(x+i*xAdd,y+i*yAdd)){
        return false;
    }
    gameObject go = (*map)(x+i*xAdd,y+i*yAdd);
    if(go==wall || go==crate){
        return false;
    } else if(go==bomb){
        return true;
    }
    return inDangerRec(x,y,xAdd,yAdd,i+1);
}

bool Enemy::inDanger(int x, int y, int & xOut, int & yOut){
    if((*map)(x,y)==bomb){
        xOut=0; 
        yOut=0;        
        return true;
    } 
    if(inDangerRec(x,y,1,0,1)){
       xOut=1;
       yOut=0;
    } else if(inDangerRec(x,y,-1,0,1)){
       xOut=-1;
       yOut=0;
    } else if(inDangerRec(x,y,0,1,1)){
       xOut=0;
       yOut=1;
    } else if(inDangerRec(x,y,0,-1,1)){
       xOut=0;
       yOut=-1;
    }
    return true;
}

void Enemy::runFrom(int x, int y, int & xOut, int & yOut){
    if(x==0){
        yOut=yPos;
        if(canMoveOn(xPos+1,yPos)){
            xOut=xPos+1;
        } else if (canMoveOn(xPos-1,yPos)){
            xOut=xPos-1;
        } else if(canMoveOn(xPos,yPos)){

        }
    }
}

