#include "../include/snake.h"

Snake::Snake(){
    tailLenght = 0;
}

Snake::~Snake(){}

Snake::Snake(Snake &o){
    lives = o.lives;
    velocity = o.velocity;
    symbol = o.symbol;
}


// **********SET FUNCTIONS***************
void Snake::setSymbol(std::string symbol) { 
    this->symbol = symbol; 
}

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
std::string Snake::getSymbol() { 
    return symbol; 
}

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

coord Snake::getSnakePos() {
    return head;
}

void Snake::increaseTailLenght(){
    tailLenght++;
}

//******move******
void Snake::move(){
    switch (snakeDirection) {
        case Directions::UP:
            head.Y -=velocity; 
            break;
        case Directions::DOWN:
            head.Y += velocity; 
            break;
        case Directions::RIGHT:
            head.X += velocity; 
            break;
        case Directions::LEFT:
            head.X -= velocity; 
            break;
    }
}
