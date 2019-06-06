//
// Created by Alexander on 27.04.2019.
//


#include "Object.h"
#include "Cell.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    Ocean * ocean1 = new Ocean;
    ocean1->addObjects(Object_Type::prey,50);
    ocean1->addObjects(Object_Type::predator,30);
    ocean1->addObjects(Object_Type::stone,0);
    ocean1->write_results_to_file(ocean1->get_prey_amount(),ocean1->get_predator_amount(),
            ocean1->get_stone_amount(),"Start");
    std::cout << "\n\n" << std::endl;
    unsigned  int thelastit = 0;
    for (int i(0); i < 100; i++)
    {
        ocean1->run();
        cout << "\n\n" << std::endl;
        ocean1->print();
        thelastit = i;
    }
    cout << thelastit;
    ocean1->write_results_to_file(ocean1->get_prey_amount(),ocean1->get_predator_amount(),
                                  ocean1->get_stone_amount(),"End");
/*
    "The amount of Preys : " << prey_amount << endl;
    stream<<"The amount of Predators : " << predator_amount << endl;
    stream  "The amount of Stones : " << stone_amount << endl;
*/

    return 0;

}
