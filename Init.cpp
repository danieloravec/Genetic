//
// Created by danza on 19.3.2017.
//

#include <iostream>

#include "Init.h"

using namespace std;

Init::Init(int _pop_size, string _target, int _mutation_rate) {
    srand(time(NULL));
    this->pop_size = _pop_size;
    this->target = _target;
    this->mutation_rate = _mutation_rate;
    this->population = Population(pop_size, mutation_rate, target);
}

void Init::evolve() {
    while(!this->population.is_finished()) {
        this->population.calc_fitness();
        this->population.natural_selection();
        this->population.generate_new_population();
        cout << "Generation number: " <<  this->population.get_generation_number() << "\n\n";
    }
    cout << "--------------------------------------------\n";
    cout << "Evolved to \"" << this->target << "\"!!! (In generation " << this->population.get_generation_number() + 1 << ")\n";
    cout << "--------------------------------------------\n";
}