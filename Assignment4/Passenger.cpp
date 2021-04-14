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

bool Passenger::login(const std::string& password) {
    if (false) { //TODO: find user in DB
        //TODO: add user in DB with hashed password
        return true;
    }
    std::size_t hashedPassword = std::hash<std::string>{}(password);
    std::size_t passwordInDB; //TODO: get password from DB
    return hashedPassword == passwordInDB;

}

Order Passenger::findCar(std::string from, std::string to, CarTypes carType) {
    //TODO:: get all working but not in ride cars with right carType
    double time = std::rand() % 180;
    double price = time + (carType*200);
    std::string driverName;
    return Order (std::move(from), std::move(to), time, price, this->name, driverName);
}

void Passenger::orderTheRide(Order order) {

}

std::pair<double, double> Passenger::whereAmI() {
    return std::pair<double, double>();
}

double Passenger::getBill(Order order) {
    return order.getPrice();
}

Passenger::Passenger(std::string name) : name(std::move(name)) {}

Passenger::Passenger() {}

std::string Passenger::toString() {
    std::string stringPassenger = name + " " + std::to_string(rating)+" " + std::to_string(orderHistory.size())+" ";
    for (const auto& order: orderHistory)
        stringPassenger.append(order+" ");
    stringPassenger.append(std::to_string(paymentMethods.size())+" ");
    for (const auto& paymentMethod: paymentMethods)
        stringPassenger.append(std::to_string(paymentMethod.first) + " " + paymentMethod.second + " ");
    stringPassenger.append(std::to_string(pinnedAddresses.size())+" ");
    for (const auto& pinnedAdress : pinnedAddresses)
        stringPassenger.append(pinnedAdress+" ");
    stringPassenger.append("\n");
    return stringPassenger;
}

void Passenger::serialize(const std::string& passengerData) {
    auto iss = std::istringstream(passengerData);
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
    size = std::stoi(str);
    for(int i = 0; i <size; i++){
        iss >> str;
        auto method = PaymentMethods(std::stoi(str));
        iss>>str;
        paymentMethods.emplace_back(method, str);
    }
    iss >> str;
    size = std::stoi(str);
    for(int i = 0; i <size; i++){
        iss >> str;
        pinnedAddresses.push_back(str);
    }
}
