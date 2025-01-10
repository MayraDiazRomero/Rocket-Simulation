#include "RocketDraw.h"
#include <iostream>
#include <string>
#include <thread>

RocketDraw::RocketDraw() : lineCount(0) {}

bool RocketDraw::openFile(const std::string& fileName) {
    file.open(fileName);
    return file.is_open();
}

void RocketDraw::closeFile() {
    file.close();
}

std::string RocketDraw::readLine() {
    std::string line;

    if (file.is_open()) {
        file.seekg(0, std::ios::end);
        std::streampos endPosition = file.tellg();

        if (lineCount >= endPosition) {
            lineCount = 0;
        }

        file.seekg(lineCount);

        if (std::getline(file, line)) {
            lineCount = file.tellg();
        }
    }
    else {
        line = "Error opening file";
    }

    return line;
}

void RocketDraw::printMoveRocket(const std::string& fileName) {
    if (openFile(fileName)) {
        std::string line = readLine();
        std::cout << line << std::endl;
        closeFile();
    }
    else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}

void RocketDraw::openAndDisplayFile(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }

        file.close();
    }
    else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}

void RocketDraw::counter() {
    std::vector<std::string> fileNames = { "rocketFlight.txt", "1.txt", "2.txt", "3.txt", "4.txt", "5.txt", "6.txt", "7.txt", "8.txt", "9.txt", "10.txt"};

    for (int i = fileNames.size() - 1; i >= 0; --i) {
        openAndDisplayFile(fileNames[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::system("cls");
    }
}