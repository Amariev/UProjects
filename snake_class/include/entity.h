#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

struct coord{int X, Y; };

class Entity
{
  protected:
    coord pos;
    std::string color;
    std::string symbol;
    
  public:
    Entity();
    Entity(Entity &o);
    Entity(coord pos);
    ~Entity();

    void setPos(coord);
    void setSymbol(std::string);

    std::string getSymbol();
    coord getPos();
};
#endif
