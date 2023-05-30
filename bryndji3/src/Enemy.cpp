#include <set>
#include <functional>

#include "Enemy.h"

Enemy::Enemy(int x, int y, int color, int health, int explosionSize, int maxBombs, int moveDelay, int bombDelay, Map * nMap,std::vector<std::unique_ptr<Character>> * nPlayers):
    Character(x,y,color,health,explosionSize,maxBombs,moveDelay+200,bombDelay,"Player"), map(nMap), players(nPlayers){}


bool Enemy::input(int in,const uint64_t now, int & xOut, int & yOut){
    if(moveTime>now){
        return false;
    }
    if(bombsUntilTargetSwitch==0){
        targetPlayer=!targetPlayer;
        bombsUntilTargetSwitch=rand()%4;
    }
    moveTime=now+moveDelay+(rand()%200);
    if(inDanger(xPos,yPos,xOut,yOut)){
        return true;
    }
    std::vector<Point> path;
    if(findPath(path,powerup)){
    } else {
        if(targetPlayer){
            if(!findPath(path,empty,players->front()->xPos,players->front()->yPos)){
                bombsUntilTargetSwitch=0;
            }
        } else {
            if(!findPath(path,crate)){
                bombsUntilTargetSwitch=0;
            }
        }
        if(path.size()==1){
            xOut=-123;
            yOut=-123;
            bombsUntilTargetSwitch--;
            return true;
        }
    }
    if(path.size()>0){
        if(inDanger(path.back().x, path.back().y,xOut,yOut)){
            return false;
        }
        xOut=path.back().x;
        yOut=path.back().y;
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

bool Enemy::canMoveOn(int x, int y, gameObject go){
    return (isValid(x,y) && ((*map)(x,y)==empty || (*map)(x,y)==powerup || (*map)(x,y)==go));
}

bool Enemy::findPath (std::vector<Point> & path, gameObject destination, int xDest, int yDest){
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
        if(xDest!=-1 && yDest!=-1){
            if(curr.x==xDest && curr.y==yDest){
                found=true;
                break;
            }
        } else if((*map)(curr.x,curr.y)==destination){
            found=true;
            break;
        }
        for(int i=0;i<4;i++){
            int x = curr.x+xAdd[i];
            int y = curr.y+yAdd[i];
            if(canMoveOn(x,y,destination) && visited.find(Point(x,y))==visited.end()){
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
    path.push_back(curr);
    std::pair<int,int> startPos(xPos,yPos);
    while(curr.lastPoint!=startPos){
        curr = *visited.find(Point(curr.lastPoint.first,curr.lastPoint.second));
        path.push_back(curr);
    }
    return true;
}

bool Enemy::inDangerRec(int x, int y, int xAdd, int yAdd, int i){
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
    if((*map)(xPos,yPos)==bomb){
        runFrom(0,0,xOut,yOut);
    } else if(inDangerRec(x,y,1,0,1)){
       runFrom(1,0,xOut,yOut);
    } else if(inDangerRec(x,y,-1,0,1)){
       runFrom(-1,0,xOut,yOut);
    } else if(inDangerRec(x,y,0,1,1)){
       runFrom(0,1,xOut,yOut);
    } else if(inDangerRec(x,y,0,-1,1)){
       runFrom(0,-1,xOut,yOut);
    } else {
        return false;
    }
    return true;
}

void Enemy::runFrom(int x, int y, int & xOut, int & yOut){
    xOut=xPos;
    yOut=yPos;
    if(x==0){
        if(canMoveOn(xPos+1,yPos)){
            xOut=xPos+1;
        } else if (canMoveOn(xPos-1,yPos)){
            xOut=xPos-1;
        } else if(y!=0 && canMoveOn(xPos,yPos+(-1*y))){
            yOut=yPos+(-1*y);
        }
    } else {
        if(canMoveOn(xPos,yPos+1)){
            yOut=yPos+1;
        } else if (canMoveOn(xPos,yPos-1)){
            yOut=yPos-1;
        } else if(canMoveOn(xPos+(-1*x),yPos)){
            xOut=xPos+(-1*x);
        }
    }
}

