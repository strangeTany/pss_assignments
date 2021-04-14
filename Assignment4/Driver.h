//
// Created by strangetany on 03.04.2021.
//

#ifndef ASSIGNMENT4_DRIVER_H
#define ASSIGNMENT4_DRIVER_H


#include <string>
#include <vector>
#include "Car.h"
#include "Status.cpp"
#include "DataBase.h"
#include "Order.h"


class Driver {
    Driver(std::string name, std::string password);

    std::string name;
    std::string password;
    double rating;
    std::vector<std::string> orderHistory;
    Car car;
    Status status;
    DataBase<Driver> db;
    DataBase<Order> orders;

public:
    bool login(const std::string &password);

    const std::vector<std::string> &getOrderHistory() const;

    const Car &getCar() const;

    Status getStatus() const;

    void setStatus(Status status);

    std::vector<Order> checkAvailableOrders();

    void acceptOrder(Order order);

    const std::string &getName() const;

    std::string toString();

    void serialize(const std::string &);

    virtual ~Driver();

    Driver(std::string name);

    Driver();

};


#endif //ASSIGNMENT4_DRIVER_H
