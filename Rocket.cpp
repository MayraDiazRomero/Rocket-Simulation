#include "Rocket.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>

Rocket::Rocket(double initialFuelLevel)
    : position(0.0), velocity(0.0), fuelTank(10000.0, initialFuelLevel), gravitationalAcceleration(9.8) {
    // Create engines and add them to the rocket
    Engine engine1(200000.0, 200.0, 1000);
    Engine engine2(200000.0, 120.0, 750);
    engines.push_back(engine1);
    engines.push_back(engine2);
}

void Rocket::igniteEngines() {
    std::cout << "Rocket ignition!" << std::endl;
}

void Rocket::updatePosition(double time) {
    double totalThrust = 0.0;
    double totalMass = getRocketMass();

    for (Engine& engine : engines) {
        double thrust = engine.getThrust();
        double fuelConsumptionRate = engine.getFuelConsumptionRate();
        double currentFuelConsumption = fuelConsumptionRate * time;

        if (currentFuelConsumption <= fuelTank.getCurrentFuelLevel()) {
            double effectiveThrust = thrust * (currentFuelConsumption / fuelConsumptionRate);
            totalThrust += effectiveThrust;
            fuelTank.consumeFuel(currentFuelConsumption);
        }
    }

    double acceleration = (totalThrust / totalMass) - gravitationalAcceleration;
    velocity += acceleration * time;
    position += velocity * time;
}

void Rocket::displayStatus() const {
    SetConsoleOutputCP(65001);
    std::cout << "Rocket status:" << std::endl;
    std::cout << "Position: " << position << " meters" << std::endl;
    std::cout << "Velocity: " << velocity << " m/s" << std::endl;
    std::cout << "Fuel Level: " << fuelTank.getCurrentFuelLevel() << " liters" << std::endl;
    std::cout << " " << std::endl;
}

double Rocket::getRocketMass() const {
    // Calculate the mass of the rocket (excluding fuel)
    double dryMass = 100000.0; // Example dry mass in kilograms
    return dryMass;
}
