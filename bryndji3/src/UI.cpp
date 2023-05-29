#include "UI.h"

UI::UI(Map * nMap){
    map=nMap;
    initscr();
    int x=0, y=0;
    addstr("Terminal size is too small.");
    while(x<(map->sizeX*xMultiplier+winYOffset+2) || y<(map->sizeY*yMultiplier)+winXOffset+2){
        getmaxyx(stdscr,y,x);
        refresh();
    }
    start_color();
    curs_set(0);
    noecho();

    //definice párů barev
    init_pair(1,COLOR_WHITE,COLOR_BLACK);   //DEFAULT
    init_pair(2,COLOR_WHITE,COLOR_WHITE);   //WALL
    init_pair(3,COLOR_BLUE,COLOR_BLACK);    //CRATE
    init_pair(4,COLOR_GREEN,COLOR_BLACK);   //BOMB
    init_pair(5,COLOR_RED,COLOR_RED);       //EXPLOSION
    init_pair(10,COLOR_MAGENTA,COLOR_BLACK);   //PLAYER1
    init_pair(11,COLOR_CYAN,COLOR_BLACK);   //PLAYER2
    init_pair(12,COLOR_YELLOW,COLOR_BLACK);   //PLAYER3
    init_pair(13,COLOR_GREEN,COLOR_BLACK);   //PLAYER4
}

UI::~UI(){
    endwin();
}

//--------------------------------------------------------------------------------------------------

void UI::start(){
    clear();
    win = newwin((map->sizeY)*3+2,(map->sizeX)*5+2,winYOffset,winXOffset);
    nodelay(win, TRUE);
    keypad(win,true);
    box(win,0,0);
    refresh();
    //print map
    for(int i=0;i<map->sizeY;i++){
        for(int j=0;j<map->sizeX;j++){
            redraw(j,i);
        }
    }
    wrefresh(win);
}

//--------------------------------------------------------------------------------------------------

int UI::getInput(){
    return wgetch(win);
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

void UI::draw(int x, int y, std::string ch [], int colorPair){
    wattron(win,COLOR_PAIR(colorPair));
    for(int i=0;i<yMultiplier;i++){
        mvwaddstr (win, yMultiplier*(y)+i+1, xMultiplier*(x)+1, ch[i].c_str());
    }
    wattroff(win,COLOR_PAIR(colorPair));
}

void UI::redraw(int x, int y){
    gameObject go=(*map)(x,y);
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
    case bomb:
        draw(x,y,bombIcon,bombColor);
        break;
    case explosion:
        draw(x,y,explosionIcon,explosionColor);
        break;
    case powerup:
        draw(x,y,powerUpIcon,powerUpColor);
        break;
    }
}

//--------------------------------------------------------------------------------------------------

void UI::update(){
    while(!map->drawQueue.empty()){
        redraw(map->drawQueue.front().first,map->drawQueue.front().second);
        map->drawQueue.pop();
    }
}