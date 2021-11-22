#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "board.h"

enum GameState {
    RUN = 1,
    END = 2
}; 

class Game
{
    public:
        Game();
        ~Game();
        Game(int time);

        void run();

        GameState getState();
        void setState(GameState);
        void clearScreen();
        void delay(int);

    private:
        GameState state;
};
#endif
