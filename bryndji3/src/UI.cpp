#include "UI.h"

UI::UI(const Map & nMap){
    map=nMap;
    initscr();
    start_color();
    curs_set(0);
    noecho();
    nodelay(win, true);

    //definice párů barev
    init_pair(1,COLOR_WHITE,COLOR_WHITE);   //WALL
    init_pair(2,COLOR_BLUE,COLOR_BLACK);    //CRATE
    init_pair(3,COLOR_BLACK,COLOR_BLACK);   //EMPTY
    init_pair(4,COLOR_GREEN,COLOR_BLACK);
}

UI::~UI(){
    endwin();
}

//--------------------------------------------------------------------------------------------------

void UI::start(){
    clear();
    win = newwin((map.sizeY)*3+2,(map.sizeX)*5+2,5,5);
    box(win,0,0);
    refresh();
    //print map
    for(int i=0;i<map.sizeY;i++){
        for(int j=0;j<map.sizeX;j++){
            redraw(j,i);
        }
    }
    wrefresh(win);
}

//--------------------------------------------------------------------------------------------------

int UI::getInput(){
    return getchar();
}

//--------------------------------------------------------------------------------------------------

void UI::drawCharacter(int x, int y, int colorPair){
    wattron(win,COLOR_PAIR(colorPair));
    for(int i=0;i<yCharacterSize;i++){
        mvwaddstr (win, yMultiplier*(y)+i+1, xMultiplier*(x)+1, characterIcon[i].c_str());
    }
    wattroff(win,COLOR_PAIR(colorPair));
}

//--------------------------------------------------------------------------------------------------

void UI::draw(int x, int y, std::string ch [yMultiplier], int colorPair){
    wattron(win,COLOR_PAIR(colorPair));
    for(int i=0;i<yMultiplier;i++){
        mvwaddstr (win, yMultiplier*(y)+i+1, xMultiplier*(x)+1, ch[i].c_str());
    }
    wattroff(win,COLOR_PAIR(colorPair));
}

void UI::redraw(int x, int y){
    gameObject go=map(x,y);
    switch (go)
    {
    case wall:
        draw(x,y,wallIcon,wallColor);
        break;
    case crate:
        draw(x,y,crateIcon,crateColor);
        break;
    case empty:
        draw(x,y,emptyIcon,emptyColor);
        break;
    }
}

//--------------------------------------------------------------------------------------------------

void UI::update(){
    wrefresh(win);
    while(!map.refreshQueue.empty()){
        redraw(map.refreshQueue.front().first,map.refreshQueue.front().second);
        map.refreshQueue.pop();
    }
}