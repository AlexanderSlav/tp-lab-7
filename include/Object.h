//
// Created by Alexander on 27.04.2019.
//

#pragma once

#include "common_settings.h"
#define  Stone_symbol '#'
#define  Prey_symbol 'f'
#define  Predator_symbol 'S'
#define  Coral_symbol '*'
enum Object_Type {Prey, Predator, Stone, Coral};
class Ocean;
class Cell;
class Object{
protected:
    Cell *cell;
    unsigned int life_time;
    Object_Type type_obj;
public:
    Object(Cell * = nullptr);
    virtual ~Object(){};
    virtual void live() = 0;
    virtual char get_symbol() = 0;
    void setCell(Cell* cell);
    void setlive(unsigned int life_time);
    Cell* getCell();
    Object_Type get_type();
    unsigned int get_live();



};

