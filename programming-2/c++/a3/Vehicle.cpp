#include "Vehicle.h"
#include<iostream>
Vehicle :: Vehicle(){

}
Vehicle :: Vehicle(int i, int w, int a, int o){
    this->id = i ;
    this->weight = w ;
    this->age = a ;
    this->occupancy = o;
}

float Vehicle :: MobilityExpense(){

    return 30000+ ((0.4*this->age)+ (0.7*this->weight));
}

float Vehicle :: MaintenanceExpense(){
    return 20000+ ((0.2*this->age));
}

float Vehicle :: RentalIncome(){
    return 0 ;
}

float Vehicle :: ShowcaseIncome(){
    return 0 ;
}

int Vehicle :: getAge(){
    return this->age;
}

int Vehicle :: getOccupancy(){
    return this->occupancy;
}

char Vehicle :: getType(){
    return this->type;
}

int Vehicle :: getID(){
    return this->id;
}



