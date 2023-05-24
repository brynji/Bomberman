#include "UI.h"

UI::UI(const Map & nMap){
    map=nMap;
    initscr();
    start_color();
    curs_set(0);

    //definice párů barev
    init_pair(1,COLOR_WHITE,COLOR_WHITE);   //WALL
    init_pair(2,COLOR_BLUE,COLOR_BLACK);    //CRATE
    init_pair(3,COLOR_BLACK,COLOR_BLACK);   //EMPTY
}

UI::~UI(){
    endwin();
}

void UI::start(){
    clear();
    win = newwin((map.sizeY)*3+2,(map.sizeX)*5+2,5,5);
    box(win,0,0);
    refresh();
    //print map
    for(int i=0;i<map.sizeY;i++){
        for(int j=0;j<map.sizeX;j++){
            redraw(i,j);
        }
    }

    wrefresh(win);
    getch();
}

void UI::draw(int x, int y, std::array<std::string,yMultiplier> ch, int colorPair){
    for(int i=0;i<yMultiplier;i++){
        wattron(win,COLOR_PAIR(colorPair));
        mvwaddstr (win, yMultiplier*(x)+i+1, xMultiplier*(y)+1, ch.at(i).c_str());
        wattroff(win,COLOR_PAIR(colorPair));
    }
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

void UI::update(){
    while(!map.refreshQueue.empty()){
        redraw(map.refreshQueue.front().first,map.refreshQueue.front().second);
        map.refreshQueue.pop();
    }
}