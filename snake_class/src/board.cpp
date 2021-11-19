#include "../include/board.h"

Board::Board (int columnas, int filas, Snake _snake, Food _food):cols{columnas}, rows{filas}{
  matrix = new int *[filas];
  for(int i = 0; i < filas; i++)
    matrix[i] = new int [columnas]{}; 
  this -> snake = _snake;
  this -> food = _food;
}

Board::~Board(){
    if(matrix!=nullptr){
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

void Board::generateMatrix()
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (i == 0 || j == 0 || i == rows -1 || j == cols -1)
      {
        matrix[i][j] = 1;
      }
      else 
      {
        matrix[i][j] = 0;
      }
    }
  }
}


void Board::drawBoard()
{
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] == 1) {
        std::cout << "\u2587" << "\u2587" ;
      }
      /*
      else if (matrix[i][j] == 8) { 8 = snake 
        //char b = 
        std::cout << "@" ;
      }
      else if (matrix[i][j] == 6) { 6 = food
        //char c = 
        std::cout << "O";
      }
      */
      else if (matrix[i][j] == 0) {
        std::cout << "  ";
      }
    }
    std::cout << "\n";
  }
}