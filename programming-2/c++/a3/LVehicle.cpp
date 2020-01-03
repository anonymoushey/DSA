#include "LVehicle.h"

LVehicle :: LVehicle(int i, int w, int a, int o): Vehicle(i,w,a,o){
    this->type = 'L';
}
float LVehicle :: RentalIncome(){
    return 34000 + (20*this->occupancy);
}
float LVehicle :: ShowcaseIncome(){
    if (this->age < 2 ) return 20000 ;
    return 40000 + 0.4*this->age;
}
LVehicle :: ~LVehicle(){
    
}