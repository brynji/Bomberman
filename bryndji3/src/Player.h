#pragma once

#include "Character.h"

///Character controlled by real person
class Player : public Character {
public:

    /**
     * Creates instance with given parameters
     * @param x coordinate where player is
     * @param y second coordinate
     * @param color color (values 10 to 13)
     * @param up int value of key
     * @param down int value of key
     * @param left int value of key
     * @param right int value of key
     * @param bomb int value of key
     * @param health number of health at the start of the game
     * @param explosionSize size of explosion at the start
     * @param maxBombs max number of bombs placed simultaneously on the map
     * @param moveDelay time in ms between moves
     * @param bombDelay time in ms before bomb explodes
     * @param name name of the player
     */
    Player(int x, int y, int color,int up, int down, int left, int right, int bomb, int health, int explosionSize, int maxBombs, int moveDelay, int bombDelay, const std::string & name);

    /**
     * Tells player which key was pressed
     * @param in int value of key that has been pressed
     * @param now current time in ms
     * @param xOut coordinate that player wants to go to
     * @param yOut coordinate that player wants to go to
     * @return signalize if player wants to move or not
     */
    bool input(int in, const uint64_t now, int& xOut, int& yOut) override;

private:
    ///Keys used to control this character
    int keyLeft;
    int keyRight;
    int keyUp;
    int keyDown;
    int keyBomb;
};