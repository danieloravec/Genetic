#include <iostream>

#include "Init.h"

using namespace std;

// Inspired by "The Coding Train"
int main() {
    int max_population = 1000;
    int mutation_rate = 1;
    string target = "The sky is dark!";
    Init evolution(max_population, target, mutation_rate);
    evolution.evolve();

    return 0;
}