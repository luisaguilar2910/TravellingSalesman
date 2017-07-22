#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std;

class City{
  private:
    string name;
    float lat;
    float lon;
  public:
    City(string _name,float _lat, float _lon);
    string getName();
    float getLat();
    float getLon();
};

#endif // CITY_H
