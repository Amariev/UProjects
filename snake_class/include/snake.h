#ifndef SNAKE_H
#define SNAKE_H

#include "entity.h"
#include "../ext/conio.h"

enum Directions {UP=1, DOWN, RIGHT, LEFT};

class Snake : public Entity
{
    private:
        int lives, tailLenght, velocity, cols, rows;
        
        Directions snakeDirection;

    public:
        Snake();
        Snake(int _rows, int _cols);
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
        bool checkEatFood(coord foodPos);
        bool checkCollision();
        void input();

        void imprimirAtributos();

        void update();
};
#endif
