//
// Created by Alexander on 27.04.2019.
//

#include "Ocean.h"
#include "Stone.h"
#include "Object.h"
#include "Prey.h"

using  namespace std;

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


void Ocean::add_stuff(Object *obj)
{
    stuff.push_back(obj);
}


void Ocean::addObjects(Object_Type type, unsigned int objects_amount)
{
    srand(time(NULL));
    for (int i(0); i < objects_amount;)
    {
        unsigned  int x = rand() % M;
        unsigned  int y = rand() % N;
        if (cells[y][x].getObject())
            continue;
        Object* new_object = nullptr;
        switch (type)
        {
            case Object_Type::prey:
                new_object = new  Prey(&cells[y][x]);
                break;
            case Object_Type::predator:
                new_object = new Predator(&cells[y][x]);
                break;
            case Object_Type::stone:
                new_object = new Stone(&cells[y][x]);
                break;
        }

    }


}


void Ocean::deleteObjects(Object *obj)
{
        obj->getCell()->killme();
}


Cell* Ocean::find_nullptr_cells(Pair crd)
{
    for (int i(0);i < 8; ++i)
    {
        size_t new_x = crd.x + rand() % 3 - 1;
        size_t new_y = crd.y + rand() % 3 - 1;
        if (new_x < N && new_y < M)
            if (cells[new_x][new_y].getObject() == nullptr)
                return &cells[new_x][new_y];

    }
    return nullptr;
}


Cell* Ocean::find_prey(Pair crd)
{
    srand(time(NULL));
    for(int i(0); i < 8; ++i)
    {
        size_t new_x = crd.x + rand() % 3 - 1;
        size_t new_y = crd.y + rand() % 3 - 1;
        if (new_x < N && new_y < M)
            if (cells[new_x][new_y].getObject() && cells[new_x][new_y].getObject()->get_type() == Object_Type::prey)
                return &cells[new_x][new_y];

    }
    return nullptr;
}


void Ocean::run()
{
    for(auto i(stuff.begin()); i != stuff.end();++i)
    {
        if ((*i)-> live() == false)
        {
            deleteObjects(*i);
            stuff.erase(i++);

        }
    }
}