#include "../include/snake.h"

Snake::Snake(){
}

Snake::Snake(int _rows, int _cols){
    this->rows = _rows;
    this->cols = _cols;
    pos.X = cols/3; pos.Y = rows/2;
    symbol = "\u26AA";
    tailLength = 0;
    lives = 5;
    velocity = 1;
    score = 0; 
}

Snake::~Snake(){}


// **********SET FUNCTIONS***************

void Snake::setLives(int lives) { 
    this->lives = lives; 
}

void Snake::setDirection(Directions direction){
    this->direction = direction;
}

void Snake::setVelocity(int velocity)
{
    this->velocity = velocity;
}

//***********GET FUNCTIONS****************

int Snake::getLives() { 
    return lives; 
}

Directions Snake::getDirection(){
    return direction;
}

int Snake::getVelocity() { 
    return velocity; 
}

void Snake::updateScore(){
    score += 10;
}

//******move******
void Snake::move(){
    switch (direction) {
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

void Snake::eatFood(){
    updateScore();
}

bool Snake::snakeCollision(Snake &o){
    if (pos.X == o.pos.X && pos.Y == o.pos.Y){
        return 1;
    }
    return 0;
}
// Rebote

void Snake::rebound(){
    switch (direction) {
        case UP:
            direction = RIGHT;
        case DOWN:
            direction = LEFT;
        case RIGHT:
            direction = UP;
        case LEFT:
            direction = DOWN;
        default:
            break;
    }
}

void Snake::rebound_edge(){
    if (pos.Y > rows-2){
        direction = UP;
    }
    else if(pos.Y < 1){
        direction = DOWN;
    }
    else if (pos.X > cols-2){
        direction = LEFT;
    }
    else if (pos.X < 1){
        direction = RIGHT;
    }
}


void Snake::imprimirAtributos(){
    std::cout << "******Atributos**********\n";
    std::cout <<"Pos X: " << pos.X << "Pos Y: "<< pos.Y << std::endl;
    std::cout << "Score: " << score << std::endl;
    std::cout << "tailLenght: " << tailLength << std::endl;
}

void Snake::update(){
    imprimirAtributos();
}
