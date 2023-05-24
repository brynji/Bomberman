#pragma once
#include<string>
#include <array>
#include <ncurses.h>

#include "Map.h"
#define xMultiplier 5
#define yMultiplier 3

class UI{
public:
    //Prepare screen for ncurses and colors
    UI(const Map & nMap);

    //Clear screen
    ~UI();

    //start of the game - draw map, show players and health
    void start();

    //Used for drawing characters
    void draw(int x, int y, std::array<std::string,yMultiplier> ch, int colorPair);

    //Draw object on pos x,y to the screen
    void redraw(int x, int y);

    void update();

WINDOW * win;
Map map;
};