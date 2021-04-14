//
// Created by strangetany on 03.04.2021.
//

#include "Driver.h"

#include <utility>
#include <sstream>

const std::vector<std::string> &Driver::getOrderHistory() const {
    return orderHistory;
}

const Car &Driver::getCar() const {
    return car;
}

Status Driver::getStatus() const {
    return status;
}

void Driver::setStatus(Status status) {
    Driver::status = status;
}

bool Driver::login(const std::string& password) {
    if (false) { //TODO: find user in DB
        //TODO: add user in DB with hashed password
        return true;
    }
    std::size_t hashedPassword = std::hash<std::string>{}(password);
    std::size_t passwordInDB; //TODO: get password from DB
    if(hashedPassword == passwordInDB) {
        setStatus(NotInRide);
        return true;
    }
    return false;
}

std::vector<Order> Driver::checkAvailableOrders() {
    //TODO: get orders from DB
    return std::vector<Order>();
}

void Driver::acceptOrder(Order order) {
    this->status = Status::InRide;

}

const std::string &Driver::getName() const {
    return name;
}

Driver::Driver(std::string name) : name(std::move(name)) {}

Driver::Driver() {}

std::string Driver::toString() {
    std::string stringDriver = name + " " + std::to_string(rating) + " " + std::to_string(orderHistory.size()) + " ";
    for (const auto& order: orderHistory)
        stringDriver.append(order + " ");
    stringDriver.append(car.getNumber()+" ");
    stringDriver.append(std::to_string(status));
    stringDriver.append("\n");
    return stringDriver;
}

void Driver::serialize(const std::string& driverData) {
    auto iss = std::istringstream(driverData);
    auto str = std::string();
    iss >> name >> str;
    rating =std::stod(str);
    iss >> str;
    int size = std::stoi(str);
    for(int i = 0; i <size; i++){
        iss >> str;
        orderHistory.push_back(str);
    }
    iss >> str;
    db.find(str);
    iss >> str;
    status = Status(std::stoi(str));
}
