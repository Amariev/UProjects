#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "snake.h"
#include "food.h"

class Board
{
  public:
  int cols; //29
  int rows; // 19
  int **matrix;

  Snake snake;
  Food food;

  Board(int columnas, int filas, Snake _snake, Food _food);
  ~Board();

  void generateMatrix();
  void drawBoard();

};

#endif

