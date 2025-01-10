#include "Tank.h"
#include <iostream>

Tank::Tank(double capacity, double initialFuelLevel)
    : capacity(capacity), currentFuelLevel(initialFuelLevel) {
    tankMass = capacity * 1.1;
}

double Tank::getCapacity() const {
    return capacity;
}

double Tank::getCurrentFuelLevel() const {
    return currentFuelLevel;
}

double Tank::getTankMass() const {
    return tankMass;
}

void Tank::refill(double amount) {
    double totalFuel = currentFuelLevel + amount;
    if (totalFuel <= capacity) {
        currentFuelLevel = totalFuel;
    }
    else {
        currentFuelLevel = capacity;
    }
}

void Tank::consumeFuel(double amount) {
    if (amount <= currentFuelLevel) {
        currentFuelLevel -= amount;
    }
    else {
        currentFuelLevel = 0.0;
    }
}