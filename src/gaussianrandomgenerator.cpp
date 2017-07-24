#include "gaussianrandomgenerator.h"

GaussianRandomGenerator::GaussianRandomGenerator(float _mean,float _variance){
    this->mean = _mean;
    this->variance = _variance;
}

int GaussianRandomGenerator::getRandomInt(int from, int to){
    float n = box_miller_marsaglia();
    float middle = (to - from)/2;
    return (int)((from + middle) + (n * (middle / 2)));
}

float GaussianRandomGenerator::getRandomFloat(float from, float to){
    float n = box_miller_marsaglia();
    float middle = (to - from)/2;
    return (from + middle) + (n * (middle / 2));
}


float GaussianRandomGenerator::box_miller_marsaglia(){
    float x,y,w;
    do{
        x = (float)((rand()%200) - 100)/100;
        y = (float)((rand()%200) - 100)/100;
        w = x*x + y*y;
    }while(w <= 0 || w >= 1);
    float m = this->mean + x * sqrt(this->variance) * sqrt(-2 * (log( w )/w));
    //For the moment we only need one value of return
    //float n = this->mean + y * sqrt(this->variance) * sqrt(-2 * (log( w )/w));
    return m;
}
