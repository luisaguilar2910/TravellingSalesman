#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <numeric>

using namespace std;

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

    int* getChromosomes();
    int getSize();
    float getFitness();
    void setFitness(float _fitness);
    void setChromosome(int* chromosome);
};

#endif // INDIVIDUAL_H
