#include "city.h"

City::City(string _name,float _lat, float _lon, int _id){
    this->name = _name;
    this->lat = _lat;
    this->lon = _lon;
    this->id = _id;
}

string City::getName(){
    return this->name;
}

float City::getLat(){
    return this->lat;
}

float City::getLon(){
    return this->lon;
}

int City::getId(){
    return this->id;
}

