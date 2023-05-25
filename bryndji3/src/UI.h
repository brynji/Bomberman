#pragma once
#include <string>
#include <ncurses.h>

#include "Map.h"
#define xMultiplier 5
#define yMultiplier 3

#define xCharacterSize 3
#define yCharacterSize 2

#define wallColor 1
#define crateColor 2
#define emptyColor 3
#define bombColor 4

class UI{
public:
    //Prepare screen for ncurses and colors
    UI(Map * nMap);

    //Clear screen
    ~UI();

    //start of the game - draw map, show players and health
    void start();

    int getInput();

    //Used for drawing characters
    void drawCharacter(int x, int y, int colorPair);

    //Draw object on pos x,y to the screen
    void redraw(int x, int y);
    void draw(int x, int y, std::string ch [], int colorPair);

    void update();

WINDOW * win;
Map * map;

std::string wallIcon    [yMultiplier] = {"     ","     ","     "};
std::string crateIcon   [yMultiplier] = {"xxxxx","xxxxx","xxxxx"};
std::string emptyIcon   [yMultiplier] = {"     ","     ","     "};
std::string powerUpIcon [yMultiplier];
std::string bombIcon    [yMultiplier] = {" \\ / ","--O--"," / \\ "};
std::string characterIcon [yCharacterSize] = {"ooo","ooo"}; 
};