//
// Created by strangetany on 03.04.2021.
//

#include "DriverGateway.h"
#include <iostream>
#include <string>

void DriverGateway::start() {
    std::cout << "Hello, please sign in. If you are not registered just write your name and new password" << std::endl
              << "Name: ";
    std::string name;
    std::string surname;
    std::string password;
    std::cin >> name;
    std::cout << std::endl << "Surname: ";
    std::cin >> surname;
    std::cout << std::endl << "Password: ";
    std::cout << std::endl;

    Driver driver(name.append(surname));
    if (driver.login(password)) {
        this->driver = driver;
        return;
    }
    std::cout << "Wrong name or password. Try again" << std::endl;
    try {
        this->start();
    } catch (std::exception_ptr current_exception()) {
        std::cout << "Too many attempts" << std::endl;
        return;
    }
}

void DriverGateway::findOrder() {
    std::cout << "Here are available orders: "<<std::endl;
    std::vector<Order> availableOrders = driver.checkAvailableOrders();
    for (int i = 0; i < availableOrders.size(); ++i) {
        std::cout<<i<<": ";
        availableOrders[i].printForDriver();
    }

}

DriverGateway::DriverGateway() {start();}

