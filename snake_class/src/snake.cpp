#include "../include/snake.h"

Snake::Snake(){
    tailLenght = 0;
    lives = 5;
    symbol = "\u2B23";
    velocity = 1;
}

Snake::~Snake(){}

Snake::Snake(Snake &o){
    lives = o.lives;
    velocity = o.velocity;
    symbol = o.symbol;
}


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
            pos.Y -=velocity; 
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
