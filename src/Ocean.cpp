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
    for(size_t i(0); i < N; ++i)
    {
        delete[]cells[i];
    }
    for(auto stuffs:stuff)
    {
        delete stuffs;
    }
}

void Ocean::print() const
{
    for (size_t i(0);i < N;++i)
    {
        for (size_t j(0);j < M;++j)
        {
           if(cells[i][j].getObject() != nullptr)
               cout << cells[i][j].getObject()->get_symbol();
           else
               cout << '.';
        }
        cout<< endl;
    }
}

void Ocean::run()
{

}

void Ocean::addObjects(Object_Type type, unsigned int objects_amount)
{
    srand(time(NULL));
    while(objects_amount > 0)
    {
        unsigned  int x = rand() % M;
        unsigned  int y = rand() % N;
        if (cells[y][x].getObject())
            continue;
        else
            {
                Object* new_object = nullptr;
                switch (type)
                {
                    case Object_Type::Prey:
                        new_object = new Prey(&cells[y][x]);
                }
            }

    }


}