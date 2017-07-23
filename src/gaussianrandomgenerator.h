#ifndef GAUSSIANRANDOMGENERATOR_H
#define GAUSSIANRANDOMGENERATOR_H

#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class GaussianRandomGenerator{
private:
    float mean;
    float variance;
    float box_miller_marsaglia();
public:
    GaussianRandomGenerator(float _mean, float _variance);
    int getRandomInt(int from, int to);
    float getRandomFloat(float from, float to);
};

#endif // GAUSSIANRANDOMGENERATOR_H
