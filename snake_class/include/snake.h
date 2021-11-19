#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>

enum Directions {UP=1, DOWN, RIGHT, LEFT};
struct coord{int X, Y; };

class Snake
{
    private:
        int lives, score, tailLenght, velocity;

        std::string symbol;
        
        Directions snakeDirection;

        coord head;

    public:
        Snake();

        Snake(Snake &o);
        ~Snake();

        void setSymbol(std::string);
        void setLives(int);
        void setTailLenght(int);
        void setVelocity(int);

        void setDirection(Directions);

        std::string getSymbol();
        int getLives();
        int getTailLenght();
        coord getSnakePos();
        int getVelocity();

        Directions getDirection();

        void move();
        void increaseTailLenght();

};
#endif
