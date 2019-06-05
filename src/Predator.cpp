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

char Predator::get_symbol()
{
    return Predator_symbol;
}

bool Predator::live()
{
    srand(time(NULL));
    if (!life_time)
        return false;
    if (am_i_hungry >= Its_time_to_eat)
    {
        if (to_have_a_breakfast())
            am_i_hungry = am_i_hungry + rand() % Its_time_to_eat + 20;
        else
            life_time--;
    }
    move();
    if (life_time < 0.2 * Life_Time_Predator)
    {
        reproduction();
    }
    if (life_time - 1 >= 0 )
        life_time--;
    else
        return false;
    return true;

}

void Predator::reproduction()
{
    Cell* new_cell = cell->empty_cell_neighbor();
    if (new_cell != nullptr)
    {
        auto* child = new Predator(new_cell);
        new_cell -> setObject(child);
        new_cell->getOcean()->add_stuff(child);
    }

}

bool Predator::to_have_a_breakfast()
{
    Cell* my_breakfast = cell->find_prey();
    if (my_breakfast != nullptr)
    {
        my_breakfast->getObject()->setlife_time(0); // eating the prey
        /*
        cell->setObject(nullptr); // replace the prey in this cell
        cell = my_breakfast;//
        my_breakfast->setObject(this);//
         */
        return true;
    }
    return false;
}
