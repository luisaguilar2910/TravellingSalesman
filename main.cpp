#include <iostream>

using namespace std;

#include "city.h"
#include "cityutils.h"

int main(int argc,char** argv){
    if(argc < 2){
        cout<<"Bad arguments"<<endl;
        cout<<"Try ./<executable name> <cities filename>"<<endl;
        return -1;
    }
    cout<<"!***************   Travelling Salesman Problem   ***************!"<<endl;

    vector<City*> cities = readCitiesFromFile(argv[1]);
    /**************************************** PREPROCESSING ****************************************/

    //Calculate distance between cities
    float** distTable = getDistTable(cities);

    //TODO: This is only a test, this going to be deleted
    for(int i=0;i<cities.size();i++){
        for(int j=0;j<cities.size();j++){
            cout<<distTable[i][j]<<"\t\t";
        }
        cout<<endl;
    }


    //Free memory used for store distances between cities
    for(int i=0;i<cities.size();i++){
        delete(distTable[i]);
    }
    delete(distTable);

    return 0;
}
