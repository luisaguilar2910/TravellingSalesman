#include "gaussianrandomgenerator.h"

GaussianRandomGenerator::GaussianRandomGenerator(float _mean,float _variance){
    this->mean = _mean;
    this->variance = _variance;
}

int GaussianRandomGenerator::getRandomInt(int from, int to){
  int res = from;
  do{
    float n = box_miller_marsaglia();
    float range = (to - from);
    res = (int)((((n + 1)*range)/2) + from);
  }while(res < from || res > to);
    return res;
}

float GaussianRandomGenerator::getRandomFloat(float from, float to){
    float n = box_miller_marsaglia();
    float middle = (to - from)/2;
    return (from + middle) + (n * (middle / 2));
}


float GaussianRandomGenerator::box_miller_marsaglia(){
    float x,y,w;
    do{
        x = (rand() / ((double) RAND_MAX))*2 - 1;
        y = (rand() / ((double) RAND_MAX))*2 - 1;
        w = x*x + y*y;
    }while(w < 0 || w > 1);
    float m = this->mean + x * sqrt(this->variance) * sqrt(-2 * (log( w )/w));
    //For the moment we only need one value of return
    //float n = this->mean + y * sqrt(this->variance) * sqrt(-2 * (log( w )/w));
    return m;
}
