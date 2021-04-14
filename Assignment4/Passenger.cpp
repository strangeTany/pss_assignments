//
// Created by strangetany on 03.04.2021.
//

#include "Passenger.h"

#include <utility>
#include <sstream>

std::vector<std::pair<PaymentMethods, std::string>> Passenger::getPaymentMethods() const {
    return paymentMethods;
}

void Passenger::setPaymentMethods(std::pair<PaymentMethods, std::string> paymentMethod) {
    Passenger::paymentMethods.push_back(paymentMethod);
}

const std::vector<std::string> &Passenger::getPinnedAddresses() const {
    return pinnedAddresses;
}

void Passenger::setPinnedAddresses(const std::vector<std::string> &pinnedAddresses) {
    Passenger::pinnedAddresses = pinnedAddresses;
}

const std::vector<std::string> &Passenger::getOrderHistory() const {
    return orderHistory;
}

bool Passenger::login(const std::string &password) {
    Passenger *passenger = db.find(this->name);
    if (passenger == nullptr) {
        this->password = password;
        db.add(this->toString());
        return true;
    }
    return password == passenger->password;

}

Order Passenger::findCar(std::string from, std::string to, CarTypes carType) {
    std::vector<Driver> allDrivers = drivers.returnAll();
    std::string driverName;

    for (auto driver : allDrivers){
        if(driver.getStatus()==NotInRide && driver.getCar().getCarType()==carType)
            driverName = driver.getName();

    }
    double time = std::rand() % 180;
    double price = time + (carType * 200);
    return Order(std::move(from), std::move(to), time, price, this->name, driverName);
}

void Passenger::orderTheRide(Order order) {

}

std::pair<double, double> Passenger::whereAmI() {
    return std::pair<double, double>();
}

double Passenger::getBill(Order order) {
    return order.getPrice();
}

Passenger::Passenger(std::string name) : name(std::move(name)) {
    db = DataBase<Passenger>("passenger");
    orders = DataBase<Order>("order");
    drivers = DataBase<Driver>("driver");

}

Passenger::Passenger() {
    db = DataBase<Passenger>("passenger");
    orders = DataBase<Order>("order");
    drivers = DataBase<Driver>("driver");

}

std::string Passenger::toString() {
    std::string stringPassenger =
            name + " " + password + " " + std::to_string(rating) + " " + std::to_string(orderHistory.size()) + " ";
    for (const auto &order: orderHistory)
        stringPassenger.append(order + " ");
    stringPassenger.append(std::to_string(paymentMethods.size()) + " ");
    for (const auto &paymentMethod: paymentMethods)
        stringPassenger.append(std::to_string(paymentMethod.first) + " " + paymentMethod.second + " ");
    stringPassenger.append(std::to_string(pinnedAddresses.size()) + " ");
    for (const auto &pinnedAdress : pinnedAddresses)
        stringPassenger.append(pinnedAdress + " ");
    stringPassenger.append("\n");
    return stringPassenger;
}

void Passenger::serialize(const std::string &passengerData) {
    auto iss = std::istringstream(passengerData);
    auto str = std::string();
    iss >> name >> str;
    rating = std::stod(str);
    iss >> str;
    int size = std::stoi(str);
    for (int i = 0; i < size; i++) {
        iss >> str;
        orderHistory.push_back(str);
    }
    iss >> str;
    size = std::stoi(str);
    for (int i = 0; i < size; i++) {
        iss >> str;
        auto method = PaymentMethods(std::stoi(str));
        iss >> str;
        paymentMethods.emplace_back(method, str);
    }
    iss >> str;
    size = std::stoi(str);
    for (int i = 0; i < size; i++) {
        iss >> str;
        pinnedAddresses.push_back(str);
    }
}

Passenger::Passenger(std::string name, std::string password) : name(std::move(name)), password(std::move(password)) {
    db = DataBase<Passenger>("passenger");
    orders = DataBase<Order>("order");
    drivers = DataBase<Driver>("driver");
}
