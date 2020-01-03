#include "AstroObservation.h"

AstroObservation :: AstroObservation(){}

AstroObservation :: AstroObservation(string _name,pair<int,int> _position,string _date){
    this->name = _name;
    this->position = _position;
    this->date = _date;
    this->pD.push_back(make_pair(_position,_date));
}

float  AstroObservation :: getBoundingBox(){
    int minX = this->pD.at(0).first.first, minY = this->pD.at(0).first.second, maxX= this->pD.at(0).first.first, maxY= this->pD.at(0).first.second; 
    vector <pair <pair<int,int>, string> > :: iterator x;
    for (x = this->pD.begin(); x < this->pD.end(); x++){
        if (x->first.first < minX)   minX = x->first.first;
        if (x->first.second < minY)  minY = x->first.second;
        if (x->first.first > maxX)   maxX = x->first.first;
        if (x->first.second > maxY)  maxY = x->first.second;
    }
    return (maxX - minY) * (maxY - minY);
}

string AstroObservation :: getName(){
    return this->name;
}

void AstroObservation :: addObservation (pair<int,int> p ,string date){
    this->pD.push_back(make_pair(p,date));
}

pair <pair <float,float >,int >AstroObservation :: avgN(){
    float x = 0, y = 0  ;
    vector <pair <pair<int,int>, string> > :: iterator i;
    for (i = this->pD.begin(); i < this->pD.end(); i++){
        x += i->first.first;
        y += i->first.second;
    }
    return make_pair(make_pair(x,y),this->pD.size());
}

 vector <pair <pair<int,int>, string> > AstroObservation:: getList(){
     return this->pD;
 }