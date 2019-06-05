//
// Created by Alexander on 27.04.2019.
//
#pragma once

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common_settings.h"


class Stone: public Object{
public:
    Stone(Cell* cell);
    ~Stone(){};
    bool live () override;
    char get_symbol() override;
};
