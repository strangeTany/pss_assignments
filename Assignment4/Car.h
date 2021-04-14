//
// Created by strangetany on 03.04.2021.
//

#ifndef ASSIGNMENT4_CAR_H
#define ASSIGNMENT4_CAR_H


#include <string>
#include "CarTypes.cpp"

class Car {
    std::string carModel;
    CarTypes carType;
    std::pair<double, double> currentCoordinates;
    std::string color;
    std::string number;
    double freeBottleOfWater;
public:
    double getFreeBottleOfWater();

    bool parkRightInFrontOfTheEntrance();

    const std::string &getNumber() const;

    std::string toString();
    void serialize(const std::string&);

    static const std::pair<double, double> &getCurrentCoordinates() ;

    CarTypes getCarType() const;
/*
 * A Car has model,
 * carType,
 * current coordinates,
 * the color and the num-ber.
 * If  the  type  is  Comfort  it  has  count  of  freeBottleOfwater
 * (it  randomly decreases during rides).
 * If the type is Business it has the methodparkRightInFrontOfTheEntrance.
 */
};


#endif //ASSIGNMENT4_CAR_H
