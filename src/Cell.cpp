//
// Created by Alexander on 27.04.2019.
//

#include "Cell.h"

void Cell::init(Pair pair_coordinates, Ocean *oc)
{
    crd = pair_coordinates;
    ocean = oc;
}

void Cell::setObject(Object * obj)
{
    this->object = obj;
}

Object* Cell::getObject() const
{
   if (object) return object;
   else
       return nullptr;
}

void Cell::killme()
{
    if(object)
    {
        delete object; // value pointed by this pointer is destroying, pointer to object is not destroying
        this->object = nullptr;  // set new value to pointer
    }
}

Pair Cell::Coordinates()
{
    return crd;
}

Ocean* Cell::getOcean()
{
    return ocean;
}

Cell* Cell::find_prey()
{
    return ocean->find_Prey(crd);
}

Cell* Cell::empty_cell_neighbor()
{
    return ocean->find_nullptr_cells(crd);
}