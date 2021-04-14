#include <iostream>
#include "DriverGateway.h"
#include "PassengerGateway.h"

int main() {
    DriverGateway driverGateway;
    PassengerGateway passengerGateway;

    passengerGateway.start();
    driverGateway.start();

    passengerGateway.orderTaxi();
    PassengerGateway anotherPassenger;
    driverGateway.findOrder();
    return 0;
}
