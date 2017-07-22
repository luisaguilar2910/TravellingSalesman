#include <iostream>

using namespace std;

#include "city.h"

int main(int argc,char** argv){
    cout<<"Travelling Salesman Problem"<<endl;
    City* city = new City("Mexico",1,2);
    cout<<city->getName()<<" "<<city->getLat()<<" "<<city->getLon()<<endl;
    return 0;
}
