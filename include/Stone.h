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
    explicit Stone(Cell* cell);
    ~Stone() override = default;
    bool live () override;
    char get_symbol() override;
    unsigned int get_size();
};
