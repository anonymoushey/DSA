#ifndef LVEHICLE
#define LVEHICLE
#include "Vehicle.h"
class LVehicle : public Vehicle{
    public :
    LVehicle(int i, int w, int a, int o);
    ~LVehicle();
    float RentalIncome();
    float ShowcaseIncome();
};
#endif 