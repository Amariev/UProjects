#ifndef FOOD_H
#define FOOD_H

#include <ctime>
#include "entity.h"

class Food : public Entity
{
  private:
    int cols, rows;
    
  public:
    Food();
    Food(int rows, int cols);
    ~Food();

    void setFoodPos();
};
#endif