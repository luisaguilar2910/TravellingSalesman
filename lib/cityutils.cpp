/**
     cityutils.cpp
     Purpose: Define a set of functions that are very useful

     @author Luis Aguilar
     @version 1.0 07/22/2017
*/
#include <math.h>
#include "cityutils.h"

//Earth's radius in metres
#define R 6371e3
//Define how convert grades to radians
#define GTOR 0.01745329252

/**
    Load all cities from a file in a vector

    @param filename The localization of the file that contains all the cities and their information
    @return cities A vector that contains all the city objects loaded from the file
*/
vector<City*> readCitiesFromFile(char* filename){
    ifstream inputFile(filename);
    string line;
    vector<City*> cities;
    int i=0;
    while(getline(inputFile,line)){
        istringstream ss(line);
        string name;
        float lon,lat;
        ss >> name >> lat >> lon;
        cities.push_back(new City(name,lat,lon,i++));
    }
    return cities;
}

/**
    Calculate the distance between two cities with is latitude and longitudeusing the Haversine formule

    @param cityA
    @param cityB

    @return dist Distance between the cities in Km
*/
float calculateDist(City* cityA,City* cityB){

    float lat1 = cityA->getLat()*GTOR;
    float lat2 = cityB->getLat()*GTOR;

    float dLat = (cityB->getLat() - cityA->getLat())*GTOR;
    float dLon = (cityB->getLon() - cityA->getLon())*GTOR;

    float a = sin(dLat/2) * sin(dLat/2)
              + cos(lat1) * cos(lat2)
              * sin(dLon/2) * sin(dLon/2);
    float c = 2 * atan2(sqrt(a),sqrt(1-a));
    return R * c;
}

float** getDistTable(vector<City*> cities){
    float** distTable = new float*[cities.size()];
    for(int i=0;i<cities.size();i++){
        distTable[i] = new float[cities.size()];
    }
    for(int i=0;i<cities.size();i++){
        distTable[i][i] = 0;
        for(int j=i+1;j<cities.size();j++){
            float dist = calculateDist(cities[i],cities[j]);
            distTable[cities[i]->getId()][cities[j]->getId()] = dist;
            distTable[cities[j]->getId()][cities[i]->getId()] = dist;
        }
    }
    return distTable;
}
