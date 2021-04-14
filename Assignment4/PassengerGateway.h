//
// Created by strangetany on 03.04.2021.
//

#ifndef ASSIGNMENT4_PASSENGERGATEWAY_H
#define ASSIGNMENT4_PASSENGERGATEWAY_H


#include "Passenger.h"

class PassengerGateway {
    Passenger passenger;
public:
    void start();
    void seeAndEditPaymentMethods();
    void seeAndEditPinnedAddresses();
    void seeOrderHistory();
    void orderTaxi();

    PassengerGateway();
};


#endif //ASSIGNMENT4_PASSENGERGATEWAY_H
