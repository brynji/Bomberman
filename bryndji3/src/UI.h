#pragma once
#include <string>
#include <array>
#include <ncurses.h>

#include "Map.h"
#define xMultiplier 5
#define yMultiplier 3

#define wallColor 1
#define crateColor 2
#define emptyColor 3

class UI{
public:
    //Prepare screen for ncurses and colors
    UI(const Map & nMap);

    //Clear screen
    ~UI();

    //start of the game - draw map, show players and health
    void start();

    int getInput();

    //Used for drawing characters
    void draw(int x, int y, std::array<std::string,yMultiplier> ch, int colorPair);

    //Draw object on pos x,y to the screen
    void redraw(int x, int y);

    void update();

WINDOW * win;
Map map;

std::array<std::string,yMultiplier> wallIcon={"     ","     ","     "};
std::array<std::string,yMultiplier> crateIcon={"xxxxx","xxxxx","xxxxx"};
std::array<std::string,yMultiplier> emptyIcon={"     ","     ","     "};
std::array<std::string,yMultiplier> powerUpIcon;
std::array<std::string,yMultiplier> bombIcon;
};