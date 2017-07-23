#ifndef CITY_H
#define CITY_H

#include <string>
using namespace std;

class City{
  private:
    string name;
    float lat;
    float lon;
    int id;
  public:
    City(string _name,float _lat, float _lon,int _id);
    string getName();
    float getLat();
    float getLon();
    int getId();
};

#endif // CITY_H
