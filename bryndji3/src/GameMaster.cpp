#include "GameMaster.h"
#include "Loader.h"
#include "Menu.h"
#include "UI.h"
#include "Bomb.h"

void GameMaster::start(){
    Loader l;
    l.loadConfig(configFile,config);
    l.loadPowerUps();

    Menu m;
    bool start;
    map = m.main(start);
    if(!start){
        closeGame();
        return;
    }
    players.emplace_back(1,10,4);
    mainLoop();
}

void GameMaster::mainLoop(){
    UI ui=(&map);
    ui.start();
    for(const auto & pl : players){
        ui.drawCharacter(pl.xPos,pl.yPos,pl.color);
    }
    int input;

    while(true){
        input = ui.getInput();
        if(input==27){break;} /////////////////////////////////////////////////
        for(auto & pl : players){
            int x,y;
            if(pl.input(input,x,y)){
                movePlayer(x,y,pl,ui);
            }
        }
        //check timeEvents(); //for bomb explosions, characters movement timers


        //test if input is really non blocking
        if(map(3,0)==wall) map(3,0)=crate;
        else map(3,0)=wall;
        ui.redraw(3,0);
    }    
}

void GameMaster::movePlayer(int x, int y, Player & pl, UI ui){
    if(x>=0 && x<map.sizeX && y>=0 && y<map.sizeY && map(x,y)>2){
        ui.redraw(pl.xPos,pl.yPos);
        pl.xPos=x;
        pl.yPos=y;
        ui.drawCharacter(x,y,pl.color);
    } else if(x==-123 && y==-123){
        map(pl.xPos,pl.yPos)=bomb;
        //Create bomb
        ui.redraw(pl.xPos,pl.yPos);
        ui.drawCharacter(pl.xPos,pl.yPos,pl.color);
    }
}

void GameMaster::closeGame(){
    
}