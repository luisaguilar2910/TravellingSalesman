#ifndef CITYUTILS_H
#define CITYUTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

#include "city.h"

vector<City*> readCitiesFromFile(char* filename);
float calculateDist(City* cityA,City* cityB);
float** getDistTable(vector<City*> cities);

#endif // CITYUTILS_H
