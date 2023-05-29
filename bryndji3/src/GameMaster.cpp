#include <chrono>

#include "GameMaster.h"
#include "Loader.h"
#include "Menu.h"
#include "Enemy.h"


void GameMaster::start(){
    if(config.size()==0){
        Loader l;
        if(!l.loadConfig(config) || !l.loadControls(controls)){
            return;
        }
        powerUpHandler.addConfig(config);
    }

    Menu m;
    bool startGame;
    int numOfPlayers=2;
    int numOfPc=0;
    std::vector<std::string> names;

    map = m.main(startGame,numOfPlayers,numOfPc,names);
    if(!startGame){
        closeGame();
        return;
    }
    int health=config.find("startingHealth")->second;
    int explosionSize=config.find("startingExplosionSize")->second;
    int maxBombs=config.find("startingMaxBombs")->second;
    int moveDelay=config.find("startingMoveDelay")->second;
    int bombDelay=config.find("startingBombDelay")->second;

    for(int i=0;i<numOfPlayers;i++){
        std::string pl="player"+std::to_string(i+1)+"_";
        players.emplace_back(std::make_unique<Player>(map.playerSpawnPositions.front().first,map.playerSpawnPositions.front().second,i+10,
            controls.find(pl+"up")->second,controls.find(pl+"down")->second,
            controls.find(pl+"left")->second,controls.find(pl+"right")->second,controls.find(pl+"bomb")->second,
            health,explosionSize,maxBombs,moveDelay,bombDelay,names[i]));
        map.playerSpawnPositions.pop();
    }
    for(int i=0;i<numOfPc;i++){
        players.emplace_back(std::make_unique<Enemy>(map.playerSpawnPositions.front().first,map.playerSpawnPositions.front().second,i+10+numOfPlayers,
        health,explosionSize,maxBombs,moveDelay,bombDelay));
        map.playerSpawnPositions.pop();
    }
    srand(time(NULL));
    mainLoop();
    reset();
    return start();
}

void GameMaster::mainLoop(){
    UI ui=(&map);
    ui.start(players);
    int input;

    while(true){
        timeNow = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        ui.update();
        for(const auto & pl : players){
            ui.drawCharacter(pl->xPos,pl->yPos,pl->color);
        }
        input = ui.getInput();
        if(input==27){break;} /////////////////////////////////////////////////
        for(auto & pl : players){
            int x,y;
            if(pl->input(input,timeNow,x,y)){
                moveCharacter(x,y,*pl,ui);
            }
        }
        int size=bombs.size();
        for(int i=0;i<size;i++){
            BombState bs = bombs[i](timeNow);
            if(bs==exploded){
                int nOfPl=players.size();
                for(int i=0;i<nOfPl;i++){
                    if(map(players[i]->xPos,players[i]->yPos)==explosion){
                        if(players[i]->hit()){
                            players.erase(players.begin()+i);
                            nOfPl--;
                            i--;
                        }
                    }
                }
            } 
            else if(bs==cleanedExplosion){
                bombs.erase(bombs.begin()+i);
                i--;
                size--;
            }
        }
        if(players.size()<=1){
            return;
        }
    }    
}

void GameMaster::moveCharacter(int x, int y, Character & pl, UI & ui){
    if(x>=0 && x<map.sizeX && y>=0 && y<map.sizeY && map(x,y)>2){
        map.drawQueue.push({pl.xPos,pl.yPos});
        pl.xPos=x;
        pl.yPos=y;
        if(map(x,y)==powerup){
            powerUpHandler.pickUp(pl);
            map(x,y)=empty;
            map.drawQueue.push({x,y});
        }
        ui.drawCharacter(x,y,pl.color);
    } else if(x==-123 && y==-123){
        if(map(pl.xPos,pl.yPos)==empty && pl.currBombs<pl.maxBombs){
            map(pl.xPos,pl.yPos)=bomb;
            bombs.emplace_back(pl.xPos,pl.yPos,pl.explosionSize,pl.bombDelay,&pl,&map,timeNow);
            map.drawQueue.push({pl.xPos,pl.yPos});
        }
    }
}

void GameMaster::reset(){
    players.clear();
    bombs.clear();
}

void GameMaster::closeGame(){
}