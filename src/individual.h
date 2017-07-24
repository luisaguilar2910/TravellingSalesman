#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

#include "gaussianrandomgenerator.h"

class Individual{
private:
    int size;
    int* chromosomes;
    float fitness;
public:
    Individual(int _size);
    ~Individual();
    static Individual* getRandIndividual(int _size);
    static Individual* getCopy(Individual* originIndividual);
    static Individual* crossover(Individual* parentA,Individual* parentB);

    int* getChromosomes();
    int getSize();
    float getFitness();
    void setFitness(float _fitness);
    void setChromosome(int* chromosome);
    void mutate(float mutateProb);
};

#endif // INDIVIDUAL_H
