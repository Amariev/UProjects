#include "../include/entity.h"

Entity::Entity(){}

Entity::Entity(Coord pos){
    this->pos = pos;
}


Entity::Entity(Entity &o){
    pos = o.pos;
    color = o.color;
    symbol = o.symbol;
}

Entity::~Entity(){}

void Entity::setPos(Coord _pos){
    this->pos = _pos;
}

void Entity::setSymbol(std::string _symbol){
    this->symbol = _symbol;
}

std::string Entity::getSymbol(){
    return symbol;
}


Coord Entity::getPos(){
    return pos;
}
