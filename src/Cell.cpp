//
// Created by Alexander on 27.04.2019.
//

#include "Cell.h"

void Cell::init(Pair p, Ocean *oc)
{
    crd = p;
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