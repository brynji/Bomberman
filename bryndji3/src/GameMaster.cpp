#include "GameMaster.h"
#include "Loader.h"
#include "Menu.h"
#include "UI.h"

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
    players.emplace_back(0,10,4);
    players.emplace_back(0,0,4);
    mainLoop();
}

void GameMaster::mainLoop(){
    UI ui(map);
    ui.start();
    for(const auto & pl : players){
        ui.drawCharacter(pl.xPos,pl.yPos,pl.color);
    }
    int input;

    while(true){
        ui.update();
        input = ui.getInput();
        if(input==27){break;} /////////////////////////////////////////////////
        for(auto & pl : players){
            int x,y;
            if(!pl.input(input,x,y)){
                break;
            }
            if(x>=0 && x<map.sizeX && y>=0 && y<map.sizeY && map(x,y)!=wall && map(x,y)!=crate){
                ui.redraw(pl.xPos,pl.yPos);
                pl.xPos=x;
                pl.yPos=y;
                ui.drawCharacter(x,y,pl.color);
            }
            // move players
            // if(map(playerMovePos)->stepOn){
            //     playerPos=playerMovePos
            // }

        }
        //check timeEvents(); //for bomb explosions, characters movement

    }    
}

void GameMaster::closeGame(){
    
}