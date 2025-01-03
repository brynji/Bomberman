#include "UI.h"

UI::UI(Map * nMap){
    map=nMap;
    initscr();
    int x=0, y=0;
    addstr("Terminal size is too small.");
    ///Calculate size of terminal needed for map and UI
    while(x<(map->sizeX*xMultiplier+winXOffset+2+xUISize) || y<(map->sizeY*yMultiplier)+winYOffset+2+yUISize){
        getmaxyx(stdscr,y,x);
        refresh();
    }
    start_color();
    curs_set(0);
    noecho();

    ///color pairs definitions
    init_pair(1,COLOR_WHITE,COLOR_BLACK);   //DEFAULT
    init_pair(2,COLOR_WHITE,COLOR_WHITE);   //WALL
    init_pair(3,COLOR_BLUE,COLOR_BLACK);    //CRATE
    init_pair(4,COLOR_GREEN,COLOR_BLACK);   //BOMB
    init_pair(5,COLOR_RED,COLOR_RED);       //EXPLOSION
    init_pair(10,COLOR_MAGENTA,COLOR_BLACK);   //PLAYER1
    init_pair(11,COLOR_CYAN,COLOR_BLACK);   //PLAYER2
    init_pair(12,COLOR_YELLOW,COLOR_BLACK);   //PLAYER3
    init_pair(13,COLOR_GREEN,COLOR_BLACK);   //PLAYER4
    init_pair(20,COLOR_RED,COLOR_BLACK);    //DEAD PLAYER NAMES
}

UI::~UI(){
    clear();
    endwin();
}

//--------------------------------------------------------------------------------------------------

void UI::start(const std::vector<std::unique_ptr<Character>> & players){
    clear();
    win = newwin((map->sizeY)*3+2,(map->sizeX)*5+2,winYOffset,winXOffset);
    nodelay(win, TRUE);
    keypad(win,true);
    box(win,0,0);

    ///Print players names
    for(uint i=0;i<players.size();i++){
        mvaddstr(winYOffset+6*i+1,4+winXOffset+map->sizeX*xMultiplier,players[i]->name.c_str());
    }
    mvaddstr(winYOffset+map->sizeY*yMultiplier+3,5,"Press Esc to quit to main menu");
    refresh();
    ///Print map
    for(int i=0;i<map->sizeY;i++){
        for(int j=0;j<map->sizeX;j++){
            redraw(j,i);
        }
    }
    wrefresh(win);
}

//--------------------------------------------------------------------------------------------------

void UI::updateBonus(const Character & pl, const std::string & bonus){
    mvaddstr(2,2,"                                                                                                     ");
    mvaddstr(2,2,(pl.name+" picked up "+bonus).c_str());
    refresh();
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

void UI::draw(int x, int y, const std::string icon [], int colorPair){
    wattron(win,COLOR_PAIR(colorPair));
    for(int i=0;i<yMultiplier;i++){
        mvwaddstr (win, yMultiplier*(y)+i+1, xMultiplier*(x)+1, icon[i].c_str());
    }
    wattroff(win,COLOR_PAIR(colorPair));
}

//--------------------------------------------------------------------------------------------------

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

//--------------------------------------------------------------------------------------------------

void UI::endScreen(const std::string & winner){
    clear();
    if(winner==""){
        mvaddstr(2,2,"Nobody has won the game :(");
    } else {
        mvaddstr(2,2,(winner+" has won the game!").c_str());
    }
    char ch=' ';
    while(ch!='\n'){
        ch=getch();
    }
}