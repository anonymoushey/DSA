#ifndef ASTRO_OBSERVATION_H
#define ASTRO_OBSERVATION_H
#include <iostream>
#include <vector>

using namespace std;
class AstroObservation{
    private: 
    string name;
    pair <int,int> position;
    string date;

    vector <pair <pair<int,int>, string> > pD ;
    public :
    AstroObservation();
    AstroObservation(string _name,pair<int,int> _position,string _data);
    float getBoundingBox();
    string getName();
    void addObservation(pair<int,int> p ,string date);
    pair<pair <float ,float >,int > avgN();
     vector <pair <pair<int,int>, string> > getList();


};

#endif