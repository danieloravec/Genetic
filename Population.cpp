//
// Created by danza on 19.3.2017.
//

#include <cmath>
#include <ctime>
#include <iostream>

#include "Population.h"

using namespace std;

Population::Population() {}

Population::Population(int _pop_max, int _mutation_rate, string _target) {
    this->pop_max = _pop_max;
    this->mutation_rate = _mutation_rate;
    this->target = _target;
    for(int i = 0; i < this->pop_max; i++)
        this->population.push_back(DNA(this->target));
    this->generation_number = 0;
}

void Population::calc_fitness() {
    for(int i = 0; i < this->population.size(); i++)
        this->population[i].calc_fitness();
}

// Selects spieces with higher fitness
void Population::natural_selection() {
    this->mating_pool.clear();
    double max_fitness = 0;
    int max_fitness_idx = 0;
    for(int i = 0; i < this->population.size(); i++)
        if(this->population[i].fitness > max_fitness) {
            max_fitness = this->population[i].fitness;
            max_fitness_idx = i;
        }
    cout << "Best string: " << this->population[max_fitness_idx].get_genes() << '\n';
    int n;
    for(int i = 0; i < this->population.size(); i++) {
        n = (int)floor(this->population[i].fitness);
        for(int j = 0; j < n; j++)
            this->mating_pool.push_back(this->population[i]);
    }
}

// Make new strings from those from Population::natural_selection()
void Population::generate_new_population() {
    for(int i = 0; i < this->population.size(); i++) {
        int rand_a = rand() % this->mating_pool.size();
        int rand_b = rand() % this->mating_pool.size();
        DNA parent_a = this->mating_pool[rand_a];
        DNA parent_b = this->mating_pool[rand_b];
        DNA child = parent_a.crossover(parent_b);
        child.target = this->target;
        child.mutate(this->mutation_rate);
        this->population[i] = child;
    }
    this->generation_number++;
}

// Got to final point?
bool Population::is_finished() {
    for(int i = 0; i < this->population.size(); i++)
        if(this->population[i].get_genes() == this->target) return true;
    return false;
}

int Population::get_generation_number() {
    return generation_number;
};