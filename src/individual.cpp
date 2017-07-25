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

float Individual::getFitness(){
    return this->fitness;
}


void Individual::setFitness(float _fitness){
    this->fitness = _fitness;
}

void Individual::setChromosome(int* chromosome){
    this->chromosomes = chromosome;
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

/**
    This function return a copy of a Individual object

    @param originIndividual The original object to do a copy
    @return copy The copy of the original object
 */

Individual* Individual::getCopy(Individual* originIndividual){
    Individual* copy = new Individual(originIndividual->getSize());
    for(int i=0;i<originIndividual->getSize();i++){
        copy->getChromosomes()[i] = originIndividual->getChromosomes()[i];
    }
    copy->setFitness(originIndividual->getFitness());
    return copy;
}

/**
     This function take two parents and generate a child using a Two-Point Crossover technique

     @param parentA
     @param parentB
     @return child generate from the two parents
 */
Individual* Individual::crossover(Individual* parentA,Individual* parentB){

    Individual* child = new Individual(parentA->getSize());

    for(int i=0;i<parentA->getSize();i++){
        child->getChromosomes()[i] = -1;
    }

    GaussianRandomGenerator* random = new GaussianRandomGenerator(0,1);
    int from = random->getRandomInt(0,parentA->getSize());
    int to = random->getRandomInt(0,parentA->getSize());
    if(from > to){
        int aux = from;
        from = to;
        to = aux;
    }

    vector<int> setElements;
    for(int i=from;i<to;i++){
        child->getChromosomes()[i] = parentA->getChromosomes()[i];
        setElements.push_back(parentA->getChromosomes()[i]);
    }


    for(int i=0;i<parentB->getSize();i++){
        int* it = find(child->getChromosomes(),child->getChromosomes()+child->getSize(),parentB->getChromosomes()[i]);
        if(it==child->getChromosomes()+child->getSize()){
          int j=0;
              while(j<parentB->getSize()){
                if(child->getChromosomes()[j] == -1){
                    child->getChromosomes()[j] = parentB->getChromosomes()[i];
                    setElements.push_back(parentB->getChromosomes()[i]);
                    j++;
                    break;
                }else{
                  j++;
                }
              }
        }
    }

    int* p = find(child->getChromosomes(),child->getChromosomes()+child->getSize(),-1);
    string f = (p!=child->getChromosomes()+child->getSize())?"With -1":"nop";
    if(p!=child->getChromosomes()+child->getSize()){
      exit(-1);
    }
    return child;
}


void Individual::mutate(float mutateProb){

    GaussianRandomGenerator* random = new GaussianRandomGenerator(0,1);

    float mut = random->getRandomFloat(0,1);

    if(mut<mutateProb){
        return;
    }

    int a = random->getRandomInt(0,this->size-1);
    int b = 0;
    do{
        b = random->getRandomInt(0,this->size-1);
    }while(b == a);
    int aux = this->chromosomes[a];
    this->chromosomes[a] = this->chromosomes[b];
    this->chromosomes[b] = aux;
}
