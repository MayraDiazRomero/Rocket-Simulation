#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include <cstdlib> // For clearing the console
#include <cstdio>
#include <windows.h>
#include <string> // getline 

// Our Header
#include "Rocket.h"
#include "Engine.h"
#include "Tank.h"
#include "RocketDraw.h"

int main() {
    //Variablen
    Rocket rocket(50000.0); // Initial fuel level of 50000 liters
    RocketDraw rocketDraw;
    const double TIME_STEP = 0.1; // Time step for each update (in seconds)
    const int NUM_UPDATES = 100; // Number of updates
    const int DELAY_MS = 100;    // Delay between updates in milliseconds
    std::string inputStartRocket;

    do {
        rocket.displayStatus(); // Initial status
        rocket.igniteEngines(); // Ignite the rocket engines
        rocketDraw.openAndDisplayFile("rocketStart.txt");
        std::cout << "Write Start to start the rocket: ";
        std::cin >> inputStartRocket;
        std::system("cls");
    } while (inputStartRocket != "start");

    rocketDraw.counter();

    for (int i = 1; i <= NUM_UPDATES; i++) {
        // Delay to simulate real-time
        std::this_thread::sleep_for(std::chrono::milliseconds(DELAY_MS));
        std::system("cls");

        rocket.updatePosition(i * TIME_STEP);
        rocket.displayStatus();
        rocketDraw.printMoveRocket("rocket.txt");
    }

    return 0;
}