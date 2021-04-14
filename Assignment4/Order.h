//
// Created by strangetany on 03.04.2021.
//

#ifndef ASSIGNMENT4_ORDER_H
#define ASSIGNMENT4_ORDER_H


#include <string>
//#include "Passenger.h"
#include "Driver.h"

class Order {
    std::string orderId;
    std::string addressFrom;
    std::string addressTo;
    double time; //in minutes
    double price;
    std::string passengerName;
    std::string driverName;
public:
    double getPrice() const;

    Order(std::string addressFrom, std::string addressTo, double time, double price, std::string passengerName, std::string driverName);

    double getTime() const;

    const std::string &getOrderId() const;

    void printForPassenger() const;
    void printForDriver() const;

    std::string toString();
    void serialize(const std::string&);
};


#endif //ASSIGNMENT4_ORDER_H
