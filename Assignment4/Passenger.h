//
// Created by strangetany on 03.04.2021.
//

#ifndef ASSIGNMENT4_PASSENGER_H
#define ASSIGNMENT4_PASSENGER_H


#include <vector>
#include <string>
#include "Order.h"
#include "PassengerGateway.h"
#include "PaymentMethods.cpp"
#include "CarTypes.cpp"

class Passenger {
    std::string name;
    double rating;
    std::vector<std::string> orderHistory;
    std::vector<std::pair<PaymentMethods, std::string>> paymentMethods;
    std::vector<std::string> pinnedAddresses;

public:

    bool login(const std::string& password);

    getPaymentMethods() const;

    void setPaymentMethods(std::pair<PaymentMethods, std::string> paymentMethod);

    const std::vector<std::string> &getPinnedAddresses() const;

    void setPinnedAddresses(const std::vector<std::string> &pinnedAddresses);

    const std::vector<std::string> &getOrderHistory() const;

    Order findCar(std::string from, std::string to, CarTypes carType);

    void orderTheRide(Order order);

    std::pair<double, double> whereAmI();

    double getBill(Order order);

    std::string toString();
    void serialize(const std::string& passengerData);

    Passenger(std::string name);

    Passenger();
};


#endif //ASSIGNMENT4_PASSENGER_H
