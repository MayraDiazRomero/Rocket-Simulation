#ifndef _ROCKET_
#define _ROCKET_
#include <iostream>
#include <fstream>
#include <vector>
#include "Engine.h"
#include "Tank.h"

class Rocket {
private:
    double position;
    double velocity;
    std::vector<Engine> engines;
    Tank fuelTank;
    double gravitationalAcceleration;  // Acceleration due to gravity

public:
    Rocket(double initialFuelLevel);
    void igniteEngines();
    void updatePosition(double time);
    void displayStatus() const;

private:
    double getRocketMass() const;
};
#endif // !_ROCKET_

