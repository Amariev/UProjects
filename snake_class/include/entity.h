#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include "colors.h"

struct Coord{int X, Y; };

class Entity
{
  protected:
    Coord pos;
    std::string color;
    std::string symbol;
    
  public:
    Entity();
    Entity(Entity &);
    Entity(Coord pos);
    ~Entity();

    void setPos(Coord);
    void setSymbol(std::string);

    std::string getSymbol();
    Coord getPos();
};
#endif
