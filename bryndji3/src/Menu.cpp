#include <iostream>
#include <ncurses.h>
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

//--------------------------------------------------------------------------------------------------

void Menu::showLeaderboard(){
    std::vector<std::string> leaders;
    if(!loader.loadLeaderboard(leaders)){
        mvaddstr(1,5,"Cannot open leaderboard file");
        getch();
        return;
    }
    auto it = leaders.begin();
    int i=2;
    while(it!=leaders.end()){
        mvaddstr(i,3,it->c_str());
        i++;
        it++;
    }
    getch();
}

//--------------------------------------------------------------------------------------------------

Map Menu::main(bool & start, int & numberOfPlayers, int & numberOfAi, std::vector<std::string> & names){
    if(!loader.loadMaps(maps)){
        start=false;
        return Map();
    }
    initscr();
    keypad(stdscr,true);
    curs_set(0);
    noecho();
    start_color();
    init_pair(1,COLOR_RED,COLOR_BLACK);
    //Main menu
    std::vector<std::string> mainOptions = {"Start","Leaderboard","Quit"};
    mvprintw(1,5,"Bomberman");
    int selected = drawMenu(2,3,mainOptions);
    clear();
    if(selected==2){
        start=false;
        endwin();
        return Map();
    } else if(selected==1){
        clear();
        showLeaderboard();
        clear();
        return main(start,numberOfPlayers,numberOfAi,names);
    }
    //Parameters of the game
    mvaddstr(0,3,"Number of players must be between 1 and 4.");
    mvaddstr(1,3,"Sum of players and Ai opponents cannot be more than 4.");
    while(true){
        mvaddstr(3,5,"Enter number of players:       ");
        numberOfPlayers=getch()-48;
        if(numberOfPlayers<1 || numberOfPlayers>4){
            continue;
        }
        addstr(std::to_string(numberOfPlayers).c_str());
        mvaddstr(5,5,"Enter number of ai opponents:  ");
        numberOfAi=getch()-48;
        if(numberOfAi<0 || numberOfPlayers+numberOfAi>4){
            mvaddstr(5,5,"                                ");
            mvaddstr(3,5,"                                ");
            continue;
        }
        break;
    }
    clear();
    //Names of players
    echo();
    for(int i=1;i<=numberOfPlayers;i++){
        mvaddstr(0,3,("Enter name of Player"+std::to_string(i)+": ").c_str());
        std::string name;
        char ch = getch();
        while(ch!='\n'){
            name.push_back(ch);
            ch=getch();
        }
        if(name.length()==0){
            i--;
            continue;
        } else if(name.length()>20){
            mvaddstr(3,3,"Name cannot be longer than 20 characters!");
            getch();
            clear();
            i--;
            continue;
        }
        names.push_back(name);
        clear();
    }
    noecho();
    endwin();
    start=true;
    return maps.at(0);
}