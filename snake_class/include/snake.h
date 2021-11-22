#ifndef SNAKE_H
#define SNAKE_H

#include "entity.h"
#include "../ext/conio.h"

enum Directions {UP=1, DOWN, RIGHT, LEFT};

class Snake : public Entity
{
    private:
        int lives, tailLength, velocity, cols, rows, score;
        Directions direction;

    public:
        Snake();
        Snake(int _rows, int _cols);
        ~Snake();

        void setLives(int);
        void setTailLength(int);
        void setVelocity(int);

        void setDirection(Directions);

        int getLives();
        int getTailLength();
        int getVelocity();

        Directions getDirection();

        void move();
        void increaseTailLength();
        void updateScore();
        void eatFood();
        bool snakeCollision(Snake &);
        void input();
        void rebound();
        void generateTail();

        void imprimirAtributos();


        void update();
};
#endif
