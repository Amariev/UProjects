#include "../include/board.h"

Board::Board (int _rows, int _cols):cols{_cols}, rows{_rows}
{
    matrix = new int *[_rows+2];
    for(int i = 0; i < _rows+2; i++)
        matrix[i] = new int [_cols+2]{}; 

    this->snake[0] = Snake(rows+2, cols+2);
    this->snake[1] = Snake(rows+2, cols+2);

    initializeSnake();
    setFoodPos();
    numBlocks = 0;
}

Board::~Board(){
    if(matrix!=nullptr){
        for (int i = 0; i < rows+2; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

void Board::generateMatrix()
{
  for (int i = 0; i < rows+2; i++)
  {
    for (int j = 0; j < cols+2; j++)
    {
      if (i == 0 || j == 0 || i == (rows+2)-1|| j == (cols+2)-1)
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

void Board::assignBox(Coord pos, int _value){
    for (int i = 1; i < (rows+2)-1; i++){
        for (int j = 1; j < (cols+2)-1; j++){
            if(i==pos.Y && j== pos.X){
                matrix[i][j] = _value;
            }
        }
    }
}

void Board::assignBlocksBox(){
    for(int i = 0; i<numBlocks; i++){
        assignBox(blocks[i], 4);
    }
}   

void Board::draw()
{
    for (int i = 0; i < rows+2; i++) {
        for (int j = 0; j < cols + 2; j++) {
            switch (matrix[i][j]) {
                case 1:
                    std::cout << "\u274E";
                    break;
                case 2:
                    std::cout << BLUE << snake[0].getSymbol() << NC;
                    break;
                case 3:
                    std::cout << GREEN << snake[1].getSymbol() << NC;
                    break;
                case 4:
                    std::cout << GREEN << "##" << NC;
                    break;
                case 5:
                    std::cout << RED << food.getSymbol() << NC;
                    break;
                default:
                    std::cout << "  ";
                    break;
            }
        }
        std::cout << "\n";
    }
}

void Board::initializeSnake()
{
  int x = cols/3;
  int y = rows/2;
  int p = 2*cols/3;
  snake[0].setPos({x,y});
  snake[1].setPos({p,y});
}
//en
void Board::snakeInput()
{
    if (kbhit()) {
        switch (getch()) {
            case 'w': case 'W':
                snake[0].setDirection(UP);
                break;
            case 's': case 'S':
                snake[0].setDirection(DOWN);
                break;
            case 'a': case 'A':
                snake[0].setDirection(LEFT);
                break;
            case 'd': case 'D':
                snake[0].setDirection(RIGHT);
                break;
            case 'i': case 'I':
                snake[1].setDirection(UP);
                break;
            case 'k': case 'K':
                snake[1].setDirection(DOWN);
                break;
            case 'j': case 'J':
                snake[1].setDirection(LEFT);
                break;
            case 'l': case 'L':
                snake[1].setDirection(RIGHT);
                break;
        }
    }
    snake[0].move();
    snake[1].move(); 
}
// Posicion de la comida
void Board::setFoodPos()
{
    srand(time(NULL));
    int x = rand()% (cols-2)+ 1;
    int y = rand()% (rows-2)+ 1;
    food.setPos({x, y});
}
// colisiones
void Board::collision(){
    if(wallCollision()){
        snake[0].rebound_edge();
        snake[1].rebound_edge();
    }
    if(checkEatFood()){
        setFoodPos();
        for(int s=0; s<2; s++){
            snake[s].eatFood();
        }
    }
    if(snake[0].snakeCollision(snake[1])){
        blocks[numBlocks] = snake[0].getPos();
        numBlocks++;
    }
    if (blocksCollision()) {
        std::cout << "Choco\n";
        /* snake[0].rebound();
        snake[1].rebound(); */
    }
    
}

bool Board::checkEatFood(){
  for(int i = 0; i<2; i++){
    if (snake[i].getPos().X == food.getPos().X  && snake[i].getPos().Y == food.getPos().Y){
        return 1;
    }   
  }
 return 0;
}

bool Board::wallCollision(){
    for(int i=0; i<2; i++){
        if (snake[i].getPos().X > (cols+2)-1 || snake[i].getPos().X < 0 || snake[i].getPos().Y > (rows+2)-1 || snake[i].getPos().Y < 0){
            return 1;
        }
    }
    return 0;
}

bool Board::blocksCollision(){
    for (int s=0; s<2; s++){
        for(int i=0; i<numBlocks ; i++){
            if (snake[s].getPos().X == blocks[i].X && snake[s].getPos().Y == blocks[i].Y){
                return 1;
            }
        }
    }
    return 0;
}

void Board::update(){
    collision();
    snake[0].update();
    snake[1].update();
    snakeInput();
    assignBox(snake[0].getPos(), 2);
    assignBox(snake[1].getPos(), 3);
    assignBox(food.getPos(), 5);
    assignBlocksBox();
    draw();
}
