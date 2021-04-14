cmake_minimum_required(VERSION 3.17)
project(Assignment4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assignment4 main.cpp Passenger.cpp Passenger.h Driver.cpp Driver.h DriverGateway.cpp DriverGateway.h PassengerGateway.cpp PassengerGateway.h Car.cpp Car.h Order.cpp Order.h PaymentMethods.cpp CarTypes.cpp Status.cpp Status.cpp DataBase.cpp DataBase.h)