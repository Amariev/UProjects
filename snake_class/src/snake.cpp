#include "../include/snake.h"

Snake::Snake(){
    tailLenght = 0;
    lives = 5;
    symbol = "\u2B23";
    velocity = 1;
}

Snake::Snake(int _rows, int _cols){
    this->rows = _rows;
    this->cols = _cols;
    pos.X = cols/3; pos.Y = rows/2;
    symbol = "\u2A00";
    tailLenght = 0;
    lives = 5;
    velocity = 1;
}

Snake::Snake(Snake &o):Entity(o){
    lives = o.lives;
    velocity = o.velocity;
}

Snake::~Snake(){}


// **********SET FUNCTIONS***************

void Snake::setLives(int lives) { 
    this->lives = lives; 
}

void Snake::setTailLenght(int tailLenght){
    this->tailLenght = tailLenght;
}

void Snake::setDirection(Directions snakeDirection){
    this->snakeDirection = snakeDirection;
}

void Snake::setVelocity(int velocity)
{
    this->velocity = velocity;
}

//***********GET FUNCTIONS****************

int Snake::getLives() { 
    return lives; 
}

int Snake::getTailLenght() { 
    return tailLenght; 
}

Directions Snake::getDirection(){
    return snakeDirection;
}

int Snake::getVelocity() { 
    return velocity; 
}

void Snake::increaseTailLenght(){
    tailLenght++;
}

//******move******
void Snake::move(){
    switch (snakeDirection) {
        case Directions::UP:
            pos.Y -= velocity; 
            break;
        case Directions::DOWN:
            pos.Y += velocity; 
            break;
        case Directions::RIGHT:
            pos.X += velocity; 
            break;
        case Directions::LEFT:
            pos.X -= velocity; 
            break;
    }
}

// *********Collisions*******
bool Snake::checkEatFood(coord foodPos){
    if (pos.X == foodPos.X  && pos.Y == foodPos.Y){
        return 1;
    }
    return 0;
}

bool Snake::checkCollision(){
    if (pos.X > cols-2 || pos.X < 1 || pos.Y > rows-2 || pos.Y < 1){
        return 1;
    }
    return 0;
}

void Snake::input()
{
    if (kbhit()) {
        switch (getch()) {
            case 'w': case 'W':
                snakeDirection = UP;
                break;
            case 's': case 'S':
                snakeDirection = DOWN;
                break;
            case 'a': case 'A':
                snakeDirection = LEFT;
                break;
            case 'd': case 'D':
                snakeDirection = RIGHT;
                break;
        }
    } 
}

void Snake::imprimirAtributos(){
    std::cout << "******Atributos**********\n";
    std::cout <<"Pos X: " << pos.X << "Pos Y: "<< pos.Y << std::endl;
}

void Snake::update(){
    imprimirAtributos();
    input();
    move();
    if (checkCollision()){
        std::cout << "Colisionnnnnnnn\n";
    }
}
