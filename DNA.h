//
// Created by danza on 19.3.2017.
//

#ifndef GENETIC_DNA_H
#define GENETIC_DNA_H

#include <vector>
#include <string>

using namespace std;

class DNA {
private:
    string genes;
    char get_random_char(); // Generates random character
public:
    string target;
    double fitness;
    DNA(string _target);
    void calc_fitness();
    DNA crossover(DNA parent_b);
    void mutate(int mutation_rate);

    // Getters
    string get_genes();
};


#endif //GENETIC_DNA_H
