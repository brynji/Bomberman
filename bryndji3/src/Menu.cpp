#include <filesystem>
#include <iostream>
#include <ncurses.h>

#include <string>
#include <vector>

#include "Menu.h"

int Menu::drawMenu(int x, int y, const std::vector<std::string> & options){
    uint selected = 0;
    int in;
    while(true){
        for(uint i=0;i<options.size();i++){
            if(i==selected){
                attron(COLOR_PAIR(1));
                mvaddstr(i+y,x,options[i].c_str());
                attroff(COLOR_PAIR(1));
            } else {
                mvaddstr(i+y,x,options[i].c_str());
            }
        }
        refresh();
        in=getch();
        if(in==KEY_UP){
            if(selected>0){
                selected=(selected-1);
            }
        } else if(in==KEY_DOWN){
            if(selected<2){
                selected=(selected+1);
            }
        } else if(in=='\n'){
            break;
        }
    }
    return selected;
}

Map Menu::main(bool & start, int & numberOfPlayers, int & numberOfAi){
    if(!loadMaps()){
        start=false;
        return Map();
    }
    std::vector<std::string> mainOptions = {"Start","Leaderboard","Quit"};
    initscr();
    keypad(stdscr,true);
    noecho();
    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);
    mvprintw(1,5,"Bomberman");
    int selected = drawMenu(2,3,mainOptions);
    if(selected==2){
        start=false;
        endwin();
        return Map();
    }
    clear();
    mvprintw(0,3,"Number of players must be between 1 and 4.");
    mvprintw(1,3,"Sum of players and Ai opponents cannot be more than 4.");
    while(true){
        mvprintw(3,5,"Enter number of players:       ");
        numberOfPlayers=getch()-48;
        if(numberOfPlayers<1 || numberOfPlayers>4){
            continue;
        }
        addstr(std::to_string(numberOfPlayers).c_str());
        mvprintw(5,5,"Enter number of ai opponents:  ");
        numberOfAi=getch()-48;
        if(numberOfAi<0 || numberOfPlayers+numberOfAi>4){
            mvprintw(5,5,"                                ");
            mvprintw(3,5,"                                ");
            continue;
        }
        break;
    }
    clear();
    endwin();
    
    start=true;
    return maps.at(0);
}

bool Menu::loadMaps(){
    try{
        const std::filesystem::path dir (mapDir);  
        for(const auto & x : std::filesystem::directory_iterator(dir)){
            maps.emplace_back(Map(x.path()));
            if(maps.back().sizeX<=0 || maps.back().sizeY<=0 || maps.back().playerSpawnPositions.size()<4){
                std::cout<<"Map \""<<x<<"\" has incorrect size or less than 4 player spawn positions.\nPress Enter to continue."<<std::endl;
                std::getchar();
                maps.pop_back();
            }
        }
    } catch (...){
        std::cout<<"Path \"examples/maps\" does not exist."<<std::endl;
        return false;
    }
    if(maps.size()<1){
        std::cout<<"No maps loaded."<<std::endl;
        return false;
    }
    return true;
}