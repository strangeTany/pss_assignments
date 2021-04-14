//
// Created by strangetany on 03.04.2021.
//

#ifndef ASSIGNMENT4_DRIVER_H
#define ASSIGNMENT4_DRIVER_H


#include <string>
#include <vector>
#include "Order.h"
#include "Car.h"
#include "Status.cpp"

class Driver {
    std::string name;
    double rating;
    std::vector<std::string> orderHistory;
    Car car;
    Status status;

public:
    bool login(const std::string& password);

    const std::vector<std::string> &getOrderHistory() const;

    const Car &getCar() const;

    Status getStatus() const;

    void setStatus(Status status);

    std::vector<Order> checkAvailableOrders();

    void acceptOrder(Order order);

    const std::string &getName() const;

    std::string toString();
    void serialize(const std::string&);
    Driver(std::string name);

    Driver();
};


#endif //ASSIGNMENT4_DRIVER_H
