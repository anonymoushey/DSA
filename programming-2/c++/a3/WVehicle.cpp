#include "WVehicle.h"

WVehicle :: WVehicle(int i, int w, int a, int o): Vehicle(i,w,a,o){
    this->type = 'W';
}

float WVehicle :: RentalIncome(){
    if (this->occupancy < 10) return 50000;
    return 100000;
}
float WVehicle :: ShowcaseIncome(){
    if (this->age < 2 ) return 20000 ;
    return 40000 + 0.4*this->age;
}

WVehicle :: ~WVehicle(){
    
}