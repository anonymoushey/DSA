#ifndef FINOPERATION
#define FINOPERATION

#include "Vehicle.h"
#include "LVehicle.h"
#include "WVehicle.h"
#include <iostream>

extern Vehicle **fleet;

class FinOperation{
    public :
    int RentalRequest(int no ,char type);
    int ShowcaseRequest(int age, char type);
    FinOperation(int t);
    void addTax();
    void accumulateExpenses(std :: string type , int id);
    void accumulateIncome(std::string type, int id);
    float profit();
    private :
    int total;
    float expenses;
    float income;

};


#endif