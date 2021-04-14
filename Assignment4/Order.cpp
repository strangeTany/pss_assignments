//
// Created by strangetany on 03.04.2021.
//

#include "Order.h"

#include <utility>
#include <iostream>
#include <ctime>
#include <sstream>

Order::Order(std::string addressFrom, std::string addressTo, double time, double price, std::string passengerName,
             std::string driverName) : addressFrom(std::move(addressFrom)), addressTo(std::move(addressTo)),
                                       time(time), price(price), passengerName(std::move(passengerName)),
                                       driverName(std::move(driverName)) {
    time_t rawtime;
    struct tm *timeInfo;
    char buffer[80];
    timeInfo = localtime(&rawtime);
    strftime(buffer, sizeof(buffer), "%d-%m-%Y-%H:%M:%S", timeInfo);
    std::string str(buffer);
    orderId = str;
}

double Order::getPrice() const {
    return price;
}

void Order::printForPassenger() const {
    std::cout << "from: " << addressFrom << " to: " << addressTo << " by: " << driverName << std::endl;

}

void Order::printForDriver() const {
    std::cout << "from: " << addressFrom << " to: " << addressTo << " for: " << passengerName << std::endl;

}

double Order::getTime() const {
    return time;
}

const std::string &Order::getOrderId() const {
    return orderId;
}

std::string Order::toString() {
    std::string stringOrder = orderId +" " + addressFrom + " " + addressTo + " " + passengerName + " "+driverName + " "+ std::to_string(
            time)+ " " + std::to_string(price)+"\n";
    return stringOrder;
}

void Order::serialize(const std::string & orderData) {
    auto iss = std::istringstream(orderData);
    auto str = std::string();
    iss >> orderId >> addressFrom >> addressTo >> passengerName>>driverName>>str;
    time = std::stod(str);
    iss>>str;
    price = std::stod(str);

}
