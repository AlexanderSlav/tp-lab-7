//
// Created by Alexander on 27.04.2019.
//

#include "Ocean.h"
#include "Stone.h"
#include "Object.h"

Ocean::Ocean()
{
    cells  = new Cell*[N];
    for (size_t i(0);i < N;++i)
    {
        cells[i] = new Cell[M];
        for (size_t j(0);j < M;++j)
        {
            cells[i][j].init({i,j},this);
        }
    }

}


Ocean::~Ocean()
{

}