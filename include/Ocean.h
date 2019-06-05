//
// Created by Alexander on 27.04.2019.
//

#pragma once
#include <vector>
#include "Cell.h"
#include "Object.h"
using namespace std;
class Ocean{
public:
    Ocean();
private:
    Cell** cells;
    vector<Object*> predators;
    vector<Object*> preys;
    vector<Object*> stones;




};
