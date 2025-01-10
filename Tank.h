#ifndef _TANK_
#define _TANK_

class Tank {
private:
    double capacity;            //Kg
    double currentFuelLevel;    //Kg
    double tankMass;            //Kg

public:
    Tank(double capacity, double initialFuelLevel);
    double getCapacity() const;
    double getCurrentFuelLevel() const;
    double getTankMass() const;
    void refill(double amount);
    void consumeFuel(double amount);
};

#endif // !_TANK_


