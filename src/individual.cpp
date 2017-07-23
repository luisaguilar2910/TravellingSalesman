#include "individual.h"

Individual::Individual(int _size){
    this->size = _size;
    this->chromosomes = new int[_size];
}

Individual::~Individual(){
    delete(this->chromosomes);
}

int* Individual::getChromosomes(){
    return this->chromosomes;
}

int Individual::getSize(){
    return this->size;
}

/**
    This function create a new random Individual, used to initialize the population.

    @param _size The size of the chromosome
    @return individual A random individual
*/
Individual* Individual::getRandIndividual(int _size){
    Individual* individual = new Individual(_size);
    vector<int> cities;

    for(int i=0;i<_size;i++){
        cities.push_back(i);
    }

    for(int i=0;i<_size;i++){
        //TODO: Create a Box-Miller-Marsaglia Polar Method for Random number from Gaussian Distribution
        int removeN = rand()%cities.size();
        individual->getChromosomes()[i] = cities[removeN];
        cities.erase(cities.begin()+removeN);
    }

    return individual;
}
