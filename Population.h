//
// Created by danza on 19.3.2017.
//

#ifndef GENETIC_POPULATION_H
#define GENETIC_POPULATION_H

#include <vector>

#include "DNA.h"

using namespace std;

class Population {
private:
    vector<DNA> mating_pool; // Better spieces will be picked with higher probability
    int mutation_rate; // In percents
    int generation_number; // Number of current generation
    int pop_max; // Maximum number of spieces
    string target;
public:
    Population();
    Population(int _pop_max, int _mutation_rate, string _target);
    vector<DNA> population;
    void calc_fitness();
    void natural_selection();
    void generate_new_population();
    bool is_finished();

    // Getters
    int get_generation_number();
};


#endif //GENETIC_POPULATION_H
