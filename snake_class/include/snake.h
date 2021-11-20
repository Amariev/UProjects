#ifndef SNAKE_H
#define SNAKE_H

#include "entity.h"

enum Directions {UP=1, DOWN, RIGHT, LEFT};

class Snake : public Entity
{
    private:
        int lives, tailLenght, velocity;
        
        Directions snakeDirection;

    public:
        Snake();

        Snake(Snake &o);
        ~Snake();

        void setLives(int);
        void setTailLenght(int);
        void setVelocity(int);

        void setDirection(Directions);

        int getLives();
        int getTailLenght();
        int getVelocity();

        Directions getDirection();

        void move();
        void increaseTailLenght();
        bool checkEatFood();
        bool checkCollision();

};
#endif
