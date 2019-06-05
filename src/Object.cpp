//
// Created by Alexander on 27.04.2019.
//

#include "Object.h"

Object_Type Object::get_type()
{
    return type_obj;
}

void Object::setCell(Cell *cell)
{
    this->cell =cell;
}

unsigned int Object::get_live()
{
    return life_time;
}

void Object::setlife_time(unsigned int life_time)
{
    this->life_time = life_time;
}

Object::Object(Cell * cell)
{
    this->cell = cell;
}

Cell* Object::getCell()
{
    return  this->cell;
}