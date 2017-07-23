#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

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
    cout<<"!***************   Travelling Salesman Problem   ***************!"<<endl;

    int population_size = atoi(argv[2]);
    vector<City*> cities = readCitiesFromFile(argv[1]);


    /**************************************** PREPROCESSING ****************************************/

    //Calculate distance between cities
    float** distTable = getDistTable(cities);

    /**************************************** INITIALIZATION ***************************************/

    vector<Individual*> population;
    for(int i=0;i<population_size;i++){
        population.push_back(Individual::getRandIndividual(cities.size()));
    }

    for(vector<Individual*>::iterator it = population.begin();it != population.end();++it){
        for(int i=0;i<(*it)->getSize();i++){
            cout<<(*it)->getChromosomes()[i]<<" ";
        }
        cout<<endl;
    }

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
