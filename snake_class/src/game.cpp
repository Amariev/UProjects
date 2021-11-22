#include "../include/game.h"

Game::Game() 
{
    this->state = GameState::RUN;
}

Game::~Game(){}

void Game::clearScreen(){
    std::cout << "\033[2J\033[1;1H";
}

void Game::delay (int a)
{
    int add=0;
    int time;
    
    time = a * 10000000;

    for (int i = 0; i < time; i++)
    {
        add *= i;
        add++;
        add++;
    }
}


void Game::run(){
    clearScreen();
    std::cout << "Bienvenido al juego\nIngresa Filas y Columnas:";
    int rows, cols;
    std::cin >> rows >> cols;
    Board *const board = new Board(rows,cols);
    while (state != END){
        clearScreen();
        delay(4);
        board->generateMatrix();
        board->update();

    }
    delete board;
}
