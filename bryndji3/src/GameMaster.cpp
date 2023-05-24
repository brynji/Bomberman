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
    mainLoop();
}

void GameMaster::mainLoop(){
    UI ui(map);
    ui.start();

    int input;

    while(true){
        input = ui.getInput();
        for(auto & pl : players){
            if(pl.input(input)){}
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