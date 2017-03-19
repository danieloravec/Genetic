//
// Created by danza on 19.3.2017.
//

#ifndef GENETIC_INIT_H
#define GENETIC_INIT_H

#include <string>

#include "Population.h"
#include "DNA.h"

using namespace std;

class Init {
private:
    int pop_size; // Size of population
    int mutation_rate; // Chance of mutation of letter (in percents)
    string target; // Target string
    Population population;
public:
    Init(int _pop_size, string _target);
    void evolve(); // To start evolution process
};


#endif //GENETIC_INIT_H
