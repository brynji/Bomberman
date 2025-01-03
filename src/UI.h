#pragma once
#include <string>
#include <ncurses.h>
#include <memory>

#include "Map.h"
#include "Character.h"

///Spaces between map and left and top edges of terminal
#define winXOffset 2
#define winYOffset 5
///Spaces below and on the right of the map, needed for names of players
#define xUISize 22
#define yUISize 3
///Number of characters representing one tile on the map
#define xMultiplier 5
#define yMultiplier 3
///Number of characters representing playable character
#define xCharacterSize 3
#define yCharacterSize 2
///Colors, defined for better readability
#define powerUpColor 1
#define emptyColor 1
#define wallColor 2
#define crateColor 3
#define bombColor 4
#define explosionColor 5
#define player1Color 10
#define player2Color 11
#define player3Color 12
#define player4Color 13

///Draws map and other information to the screen
class UI{
public:
    ///Prepare screen for ncurses and colors
    UI(Map * nMap);

    ///Clear screen
    ~UI();

    /**
     * start of the game - draw map, show players names
     * @param players array of players to print names
     */
    void start(const std::vector<std::unique_ptr<Character>> & players);

    /**
     * Prints information about collected powerUp
     * @param pl player which collected powerUp
     * @param bonus which powerUp was collected
     */
    void updateBonus(const Character & pl, const std::string & bonus);

    /**
     * Reads input in non-blocking mode
     * @return int value of pressed key, or -1 if no input is ready
     */
    int getInput();

    /**
     * Draw character to the screen on x,y
     * @param x coordinate
     * @param y coordinate
     * @param colorPair color of the player, values 10 to 13
     */
    void drawCharacter(int x, int y, int colorPair);

    /**
     * Refresh gameObject on x,y in the map, expands to draw(x,y,icon [],colorPair)
     * @param x coordinate
     * @param y coordinate
     */
    void redraw(int x, int y);

    /**
     * Draws icon in colorPair color to the x,y coordinates
     * @param x coordinate
     * @param y coordinate
     * @param icon string array which will be printed to the screen
     * @param colorPair color of drawn object
     */
    void draw(int x, int y, const std::string icon [], int colorPair);

    /**
     * Redraw all tiles of the map from drawQueue
     */
    void update();

    /**
     * Print winners name and wait for confirmation
     * @param winner name to be printed
     */
    void endScreen(const std::string & winner);

private:
///Window with drawn map
WINDOW * win;
///Map that is currently played
Map * map;

///Icons of gameObjects
const std::string wallIcon    [yMultiplier] = {"     ","     ","     "};
const std::string crateIcon   [yMultiplier] = {"xxxxx","xxxxx","xxxxx"};
const std::string emptyIcon   [yMultiplier] = {"     ","     ","     "};
const std::string powerUpIcon [yMultiplier] = {" ___ ","/ ? \\","-----"};
const std::string bombIcon    [yMultiplier] = {" \\ / ","--O--"," / \\ "};
const std::string explosionIcon    [yMultiplier] = {"     ","     ","     "};
const std::string characterIcon [yCharacterSize] = {"ooo","ooo"}; 
};