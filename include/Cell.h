//
// Created by Alexander on 27.04.2019.
//

#pragma once
#include "Object.h"
typedef size_t coord_t;
class Ocean;
class Cell{
    friend Ocean;
public:
    Cell();
    void setObject(Object* data);

private:
    int Cell_X;
    int Cell_Y;
    Object* object;
    Ocean* ocean;



};
