//
// Created by danza on 19.3.2017.
//

#include <ctime>

#include "DNA.h"

using namespace std;

DNA::DNA(string _target) {
    this->target = _target;
    // Random initial data generation
    for(int i = 0; i < _target.size(); i++)
        this->genes.push_back(get_random_char());
    this->fitness = 0;
}

// Generates random integer in interval [32; 122] (ASCII value)
char DNA::get_random_char() {
    char random_char = (char)((rand() % 91) + 32);
    return random_char;
}

// Fitness if number of letters identical to those in final string (in value and position)
void DNA::calc_fitness() {
    int act_fitness = 0;
    for(int i = 0; i < this->target.size(); i++) {
        if(this->target[i] == this->genes[i])
            act_fitness++;
    }
    this->fitness = act_fitness;
}

// Perform crossing of 2 string (take part from each of those 2)
DNA DNA::crossover(DNA parent_b) {
    int midpoint = rand() % this->genes.size();
    DNA child(this->genes);
    for(int i = 0; i < midpoint; i++)
        child.genes[i] = this->genes[i];
    for(int i = midpoint; i < parent_b.genes.size(); i++)
        child.genes[i] = parent_b.genes[i];
    return child;
}

// Change letter in string (small probability)
void DNA::mutate(int mutation_rate) {
    for(int i = 0; i < this->genes.size(); i++) {
        int rand_num = (rand() % 100) + 1;
        if(rand_num <= mutation_rate)
            this->genes[i] = get_random_char();
    }
}

string DNA::get_genes() {
    return this->genes;
}