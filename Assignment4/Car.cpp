//
// Created by strangetany on 03.04.2021.
//

#include <sstream>
#include "Car.h"

double Car::getFreeBottleOfWater() {
    if (this->carType > CarTypes::Comfort){
        freeBottleOfWater = std::rand() % 1001;
        return freeBottleOfWater;
    }
    return 0;
}

bool Car::parkRightInFrontOfTheEntrance() {
    if (this->carType == CarTypes::Business)
        return true;
    return false;
}

const std::string &Car::getNumber() const {
    return number;
}

std::string Car::toString() {
    std::string stringCar = number + " " + carModel + " " + std::to_string(carType) + " " +color+"\n";
    return stringCar;
}

void Car::serialize(const std::string & carData) {
    auto iss = std::istringstream(carData);
    auto str = std::string();
    int n;
    iss >> number>>carModel>>n>>color;
    carType = CarTypes(n);
}

const std::pair<double, double> &Car::getCurrentCoordinates() {
    return std::pair<double, double>(std::rand(), std::rand());
}

