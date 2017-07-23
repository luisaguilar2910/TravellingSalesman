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
public:
    Individual(int _size);
    ~Individual();
    static Individual* getRandIndividual(int _size);
    int* getChromosomes();
    int getSize();
};

#endif // INDIVIDUAL_H
