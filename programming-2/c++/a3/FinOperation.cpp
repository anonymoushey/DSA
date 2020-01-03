#include "FinOperation.h"
#include <iostream>
FinOperation :: FinOperation(int t){
    this->total = t;
    this->expenses = 0;
    this->income = 0;
}
int FinOperation :: RentalRequest(int no ,char type){
    int bestno = 0 ;
        int bestid =0;
        for (int i = 0 ; i < this->total ; i++){
            if (fleet[i]->getOccupancy() == no && fleet[i]->getType() == type){
                return fleet[i]->getID();

            }
            else if (bestno == 0 && fleet[i]->getOccupancy()>no && fleet[i]->getType()==type){
                bestno = fleet[i]->getOccupancy();
                bestid = fleet[i]->getID();
            }
            else if (fleet[i]->getOccupancy()<bestno && fleet[i]->getOccupancy()>no && fleet[i]->getType()==type ){
                bestno = fleet[i]->getOccupancy();
                bestid = fleet[i]->getID();
             } 
        }
        return bestid;

}

int FinOperation :: ShowcaseRequest(int age,char type){
    int bestno = 0 ;
        int bestid =0;
        for (int i = 0 ; i < this->total ; i++){
            if (fleet[i]->getAge() == age && fleet[i]->getType() == type){
                return fleet[i]->getID();
            }
            else if (bestno == 0 && fleet[i]->getAge()>age && fleet[i]->getType()==type){
                bestno = fleet[i]->getAge();
                bestid = fleet[i]->getID();
            }
            else if (fleet[i]->getAge()<bestno && fleet[i]->getOccupancy()>age && fleet[i]->getType()==type )
                bestno = fleet[i]->getAge();
                bestid = fleet[i]->getID();
        } 
        return bestid;
}

void FinOperation::accumulateExpenses(std :: string type, int id){
    int j = -1;
    for (int i = 0 ; i < total ; i++){
        if (fleet[i]->getID()==id){
            j = i ;
        }
    }
    
    if (!type.compare("MT")){
        this->expenses = this->expenses + fleet[j]->MobilityExpense();
    }
    if (!type.compare("MN")){
        this->expenses = this->expenses + fleet[j]->MaintenanceExpense();
    }
}

void FinOperation :: accumulateIncome(std::string type, int id){
   int j = -1;
    for (int i = 0 ; i < total ; i++){
        if (fleet[i]->getID()==id){
            j = i ;
        }
    }
    if (!type.compare("RR")){
        this->income  = this->income + fleet[j]->RentalIncome();
    }
    if (!type.compare("SR")){
        this->income = this->income + fleet[j]->ShowcaseIncome();
    }

}

float FinOperation::  profit(){
    
    return this->income - this->expenses;
}


void FinOperation :: addTax(){
    this->expenses = this->expenses+6000;
}