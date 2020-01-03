#ifndef Vehicle_F
#define Vehicle_F

class Vehicle
{
protected:
    int id ; 
    int weight;
    int age ;
    int occupancy;
protected :    
    char type ;
public:
    Vehicle();
    Vehicle(int i, int w, int a, int o);
    float MobilityExpense();
    float MaintenanceExpense();
    virtual float RentalIncome();
    virtual float ShowcaseIncome();
    int getAge();
    int getID();
    int getOccupancy();
    char getType();
    
};
#endif

