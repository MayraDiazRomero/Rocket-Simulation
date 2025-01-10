#ifndef _ENGINE_
#define _ENGINE_

class Engine {
private:
    double thrust;                  //N
    double fuelConsumptionRate;     //kg/s
    double engineMass;              //Kg

public:
    Engine(double thrust, double fuelConsumptionRate, double mass);
    double getThrust() const;
    double getMass() const; 
    double getFuelConsumptionRate() const;
};

#endif // !_ENGINE_
