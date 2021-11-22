#ifndef BOARD_H
#define BOARD_H

#include "colors.h"
#include "snake.h"
#include "food.h"
#include <ctime>

class Board
{
    public:
    int cols;
    int rows; 
    int **matrix;
    Coord blocks[100];
    int numBlocks;

    Snake snake[2];
    Food food;

    Board(int cols, int rows);
    ~Board();

    void generateMatrix();
    void assignBox(Coord, int);
    void assignBlocksBox();
    void draw();

    void initializeSnake(); //
    void snakeInput(); 
    void setFoodPos();

    void collision();
    bool wallCollision();
    bool checkEatFood();
    bool blocksCollision();
    
    void update();
};

#endif
