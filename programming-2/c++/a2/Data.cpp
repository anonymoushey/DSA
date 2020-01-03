#include <iostream>
#include <string>
#include "Data.h"

Data :: Data(std :: string name, int index) : _index(index){
    this->_name = name;
}

std::string Data :: getName(){
    return _name;
}
std :: ostream& operator <<(std :: ostream &out,  Data *d){
    out <<d->getIndex() << " " <<  d->getName()  << "\t" ;
    return out;
}
int Data :: getIndex(){
    return _index;
}

