//
// Created by filip on 7/5/20.
//
#include "fuel.h"
#include <iostream>
#include <fstream>

int fuelSimple(std::string puzzleInPath) {
    std::ifstream readFile(puzzleInPath);
    std::string output;
    int fuel = 0;
    while(getline(readFile, output)) {
        fuel += fuelRequired(std::stoi(output));
    }
    readFile.close();
    return fuel;
}

int fuelComplex(std::string puzzleInPath) {
    std::ifstream readFile(puzzleInPath);
    std::string output;
    int fuel = 0;
    while(getline(readFile, output)) {
        int currentFuel = 0;
        currentFuel = fuelRequired(std::stoi(output));

        while(currentFuel > 0) {
            fuel += currentFuel;
            currentFuel = fuelRequired(currentFuel);

        }
    }
    readFile.close();
    return fuel;
}

int fuelRequired(int mass) {
    return (mass/3) - 2;
}