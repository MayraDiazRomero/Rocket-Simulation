#include "Engine.h"
#include <iostream>

Engine::Engine(double thrust, double fuelConsumptionRate, double mass)
    : thrust(thrust), fuelConsumptionRate(fuelConsumptionRate), engineMass(mass) {}

double Engine::getThrust() const {
    return thrust;
}

double Engine::getMass() const {
    return engineMass;
}

double Engine::getFuelConsumptionRate() const {
    return fuelConsumptionRate;
}