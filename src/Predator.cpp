//
// Created by Alexander on 27.04.2019.
//


#include "Predator.h"
#include <iostream>

Predator::Predator(Cell * c):Object(c)
{
    life_time = Life_Time_Predator;
    type_obj = Object_Type::Predator;

}


void Predator::move()
{
    Cell* new_cell = cell->empty_cell_neighbor();
    if (new_cell != nullptr)
    {
        cell->setObject(nullptr);
        cell = new_cell;
        new_cell->setObject(this);
    }
}
