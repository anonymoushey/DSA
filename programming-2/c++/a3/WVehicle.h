#ifndef WVEHICLE
#define WVEHICLE
#include "Vehicle.h"
class WVehicle : public Vehicle{
    public :
    WVehicle(int i, int w, int a, int o);
    ~WVehicle();
    float RentalIncome();
    float ShowcaseIncome();

};
#endif