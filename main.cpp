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
    cout<<"Travelling Salesman Problem"<<endl;
    vector<City*> cities = readCitiesFromFile(argv[1]);
    for(vector<City*>::iterator it = cities.begin(); it != cities.end();++it){
        cout<<(*it)->getName()<<" "<<(*it)->getLat()<<" "<<(*it)->getLon()<<endl;
    }
    return 0;
}
