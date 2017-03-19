#include <iostream>

#include "Init.h"

using namespace std;

// Inspired by "The Coding Train"
int main() {
    int max_population = 1000;
    string target = "The sky is dark!";
    Init evolution(max_population, target);
    evolution.evolve();

    return 0;
}