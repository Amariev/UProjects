#include "../include/food.h"

Food::Food(){
}


Food::~Food(){}

void Food::setFoodPos()
{
    srand(time(NULL));
    pos.X = rand()% cols+ 1;
    pos.Y = rand()% rows+ 1;
}