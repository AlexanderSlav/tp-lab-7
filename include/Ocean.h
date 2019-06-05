//
// Created by Alexander on 27.04.2019.
//

#pragma once
#include <vector>
#include "Cell.h"
#include "Predator.h"
#include "Stone.h"
#include "Prey.h"
#include "common_settings.h"
#include "Object.h"
#include <list>
using namespace std;
class Ocean{
    friend Cell;
public:
    Ocean();
    ~Ocean();
    void print() const;
    void addObjects(Object_Type type, unsigned int objects_amount);
    void run();
    void deleteObjects(Object* obj);
    void addStuff(Object* obj);
    Cell* find_nullptr_cells(Pair crd);
    Cell* find_Prey(Pair crd);
private:
    Cell** cells;
    list <Object*> stuff;





};
