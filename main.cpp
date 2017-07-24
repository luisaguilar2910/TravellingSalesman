#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <ios>

using namespace std;

#include "gaussianrandomgenerator.h"
#include "city.h"
#include "cityutils.h"
#include "individual.h"

int main(int argc,char** argv){
    if(argc < 3){
        cout<<"Bad arguments"<<endl;
        cout<<"Try ./<executable name> <cities_filename> <population_size>"<<endl;
        return -1;
    }
    srand(time(0));

    cout<<"/********************************************* Travelling Salesman Problem *********************************************/"<<endl<<endl;

    int population_size = atoi(argv[2]);
    vector<City*> cities = readCitiesFromFile(argv[1]);

    cout<<"Population Size\t=\t"<<population_size<<endl;
    cout<<"Number of cities\t=\t"<<cities.size()<<endl;
    cout<<endl;

    /**************************************** PREPROCESSING ****************************************/

    //Calculate distance between cities
    float** distTable = getDistTable(cities);

    /**************************************** INITIALIZATION ***************************************/

    vector<Individual*> population;
    Individual* best = NULL;

    for(int i=0;i<population_size;i++){
        population.push_back(Individual::getRandIndividual(cities.size()));
    }

     cout<<"/-------------------------------------------------- Population Fitness --------------------------------------------------/"<<endl<<endl;

     //Calculate each indivial's fitness
    for(vector<Individual*>::iterator it = population.begin();it != population.end();++it){

        float fitness = 0;
        for(int i=0;i<(*it)->getSize()-1;i++){
            fitness += distTable[(*it)->getChromosomes()[i]][(*it)->getChromosomes()[i+1]];
        }
        (*it)->setFitness(1/fitness);
        cout<<(*it)->getFitness()<<" ";
        if(best == NULL || best->getFitness() < (*it)->getFitness()){
            best = Individual::getCopy((*it));
        }
    }

    cout<<endl<<endl;

    cout<<"/-------------------------------------------------- Selection --------------------------------------------------/"<<endl<<endl;

    //Fitness - Proportionate Selection
    float* fitnessRoulette = new float[population.size()];

    fitnessRoulette[0] = population[0]->getFitness();
    for(int i=1;i<population.size();i++){
        fitnessRoulette[i] = population[i]->getFitness() + fitnessRoulette[i - 1];
    }
    cout<<endl;

    //Print probability of to be selected
    float total = 0;
    for(int i=0;i<population.size();i++){
        cout<<"i = "<<i<<"\t"<<setprecision(8)
            <<population[i]->getFitness()<<"\t\t"
            <<(population[i]->getFitness()/fitnessRoulette[population.size()-1])*100<<"%"<<endl;
        total += (population[i]->getFitness()/fitnessRoulette[population.size()-1])*100;
    }
    cout<<"Total\t\t"<<total<<endl<<endl;

    GaussianRandomGenerator* random = new GaussianRandomGenerator(0,1);

    //TODO: Replace this code for a Binary Search
    float n = random->getRandomFloat(fitnessRoulette[population.size()-1],0);
    int p1 = 0;
    for(int i=1;i<population.size();i++){
        if(fitnessRoulette[i-1] < n && n < fitnessRoulette[i]){
            p1 = i;
            break;
        }
    }
    int p2 = 0;
    do{
        float n = random->getRandomFloat(fitnessRoulette[population.size()-1],0);
        for(int i=1;i<population.size();i++){
            if(fitnessRoulette[i-1] < n && n < fitnessRoulette[i]){
                p2 = i;
                break;
            }
        }
    }while (p2 == p1);

    cout<<"Select to be parent "<<population[p1]->getFitness()<<endl;
    cout<<"Select to be parent "<<population[p2]->getFitness()<<endl;

    Individual* child1 = Individual::crossover(population[p1],population[p2]);
    Individual* child2 = Individual::crossover(population[p2],population[p1]);




    cout<<"/-------------------------------------------------- END --------------------------------------------------/"<<endl<<endl;


    cout<<"Best Fitness "<<best->getFitness()<<endl;
    delete(best);
    //Free memory used for store distances between cities
    for(int i=0;i<cities.size();i++){
        delete(distTable[i]);
    }
    delete(distTable);

    //Free memory used for population
    for(vector<Individual*>::iterator it = population.begin();it != population.end();++it){
        delete(*it);
    }

    return 0;
}
