#include "GameMaster.h"
#include "Loader.h"
#include "Menu.h"
#include "Enemy.h"

void GameMaster::start(){
    Loader l;
    if(!l.loadConfig(config) || !l.loadControls(controls)){
        return;
    }
    powerUpHandler.addConfig(config);

    Menu m;
    bool start;
    map = m.main(start);
    if(!start){
        closeGame();
        return;
    }
    int numOfPlayers=2;
    int numOfPc=0;
    for(int i=0;i<numOfPlayers;i++){
        std::string pl="player"+std::to_string(i+1)+"_";
        players.emplace_back(std::make_unique<Player>(map.playerSpawnPositions.front().first,map.playerSpawnPositions.front().second,i+10,
            controls.find(pl+"up")->second,controls.find(pl+"down")->second,
            controls.find(pl+"left")->second,controls.find(pl+"right")->second,controls.find(pl+"bomb")->second));
        map.playerSpawnPositions.pop();
    }
    for(int i=0;i<numOfPc;i++){
        players.emplace_back(std::make_unique<Enemy>(map.playerSpawnPositions.front().first,map.playerSpawnPositions.front().second,4));
        map.playerSpawnPositions.pop();
    }
    srand(time(NULL));
    mainLoop();
}

void GameMaster::mainLoop(){
    UI ui=(&map);
    ui.start();
    int input;

    while(true){
        ui.update();
        for(const auto & pl : players){
            ui.drawCharacter(pl->xPos,pl->yPos,pl->color);
        }
        input = ui.getInput();
        if(input==27){break;} /////////////////////////////////////////////////
        for(auto & pl : players){
            int x,y;
            if(pl->input(input,x,y)){
                moveCharacter(x,y,*pl,ui);
            }
        }
        if(!bombs.empty()){
            BombState bs = bombs.front()();
            if(bs==exploded){
                int nOfPl=players.size();
                for(int i=0;i<nOfPl;i++){
                    if(map(players[i]->xPos,players[i]->yPos)==explosion){
                        if(players[i]->hit()==true){
                            //player died
                            players.erase(players.begin()+i);
                            nOfPl--;
                            i--;
                        }
                    }
                }
            } 
            else if(bs==cleanedExplosion){
                bombs.pop();
            }
        }
        if(players.size()<=1){
            return;
        }
        //check timeEvents(); //for bomb explosions, characters movement timers
    }    
}

void GameMaster::moveCharacter(int x, int y, Character & pl, UI & ui){
    if(x>=0 && x<map.sizeX && y>=0 && y<map.sizeY && map(x,y)>2){
        ui.redraw(pl.xPos,pl.yPos);
        pl.xPos=x;
        pl.yPos=y;
        if(map(x,y)==powerup){
            powerUpHandler.pickUp(pl);
            map(x,y)=empty;
            ui.redraw(x,y);
        }
        ui.drawCharacter(x,y,pl.color);
    } else if(x==-123 && y==-123){
        if(map(pl.xPos,pl.yPos)==empty && pl.currBombs<pl.maxBombs){
            map(pl.xPos,pl.yPos)=bomb;
            bombs.emplace(pl.xPos,pl.yPos,pl.explosionSize,&pl,&map);
            ui.redraw(pl.xPos,pl.yPos);
            ui.drawCharacter(pl.xPos,pl.yPos,pl.color);
        }
    }
}

void GameMaster::closeGame(){

}