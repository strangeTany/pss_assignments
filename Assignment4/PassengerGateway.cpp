//
// Created by strangetany on 03.04.2021.
//

#include "PassengerGateway.h"
#include <iostream>

void PassengerGateway::start() {
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

    Passenger passenger(name.append(surname));
    if (passenger.login(password)) {
        this->passenger = passenger;
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

void PassengerGateway::orderTaxi() {
    std::cout<< "Good something! Where are you now?"<<std::endl;
    std::vector<std::string> pinnedAddresses = passenger.getPinnedAddresses();
    for (int i = 0; i < pinnedAddresses.size(); ++i) {
        std::cout <<'['<< i << "]: ";
        std::cout << pinnedAddresses[i] << std::endl;
    }
    std::cout<<"[n] New address"<<std::endl;
    std::string answer;
    std::cin >> answer;
    std::string from;
    if(answer == "n"){
        std::cout<< "Enter address: ";
        std::cin>>from;
        std::cout<<std::endl;
    }else{
        int number = std::stoi(answer);
        from = pinnedAddresses[number];
    }
    std::cout<<"Where you go?(write number of address or n to create new)"<<std::endl;
    std::cin >> answer;
    std::string to;
    if(answer == "n"){
        std::cout<< "Enter address: ";
        std::cin>>to;
        std::cout<<std::endl;
    }else{
        int number = std::stoi(answer);
        to = pinnedAddresses[number];
    }
    std::cout<<"Choose car type: 0-Economy, 1-Comfort, 2-ComfortPlus, 3-Business"<<std::endl;
    int number;
    CarTypes carType;
    std::cin>>number;
    carType = CarTypes(number);
    std::cout<<std::endl;
    Order newOrder = passenger.findCar(from, to, carType);
    std::cout<<"You ride take "<<newOrder.getTime()<<" minutes and will cost "<<newOrder.getPrice()<<std::endl;
    std::cout<<"Do you want to order?[y/N]"<<std::endl;
    std::cin >> answer;
    if(answer=="y"){
        std::cout<<"Do you want to change payment method [y/N]"<<std::endl;
        std::cin >> answer;
        if(answer=="y"){
            std::cout<<"You do not really want to";
        }
        passenger.orderTheRide(newOrder);
    }

}

void PassengerGateway::seeAndEditPaymentMethods() {
    std::cout << "Here are your current payment methods: " << std::endl;
    std::vector<std::pair<PaymentMethods, std::string>> paymentMethods = passenger.getPaymentMethods();
    for (int i = 0; i < paymentMethods.size(); ++i) {
        PaymentMethods method = paymentMethods[i].first;
        std::cout << i << ": ";
        switch (method) {
            case 0:
                std::cout << "Card ";
                break;
            case 1:
                std::cout << "Google Pay ";
                break;
        }
        std::cout << paymentMethods[i].second << std::endl;
    }
    std::cout << "Would you like to add new payment method?[y/N]" << std::endl;
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        std::cout << std::endl << "Choose method: 0-Card, 1-Google Pay" << std::endl;
        int newMethod;
        std::cin >> newMethod;
        if(newMethod != 1 && newMethod != 0){
            std::cout<<"Something went wrong..."<<std::endl;
            return;
        }
        std::string paymentDetails;
        std::cout << std::endl << "Enter card number: " << std::endl;
        std::cin >> paymentDetails;
        passenger.setPaymentMethods(std::pair<PaymentMethods, std::string>(PaymentMethods(newMethod), paymentDetails));
    }
}

void PassengerGateway::seeAndEditPinnedAddresses() {
    std::cout << "Here are your current pinned addresses: " << std::endl;
    std::vector<std::string> pinnedAddresses = passenger.getPinnedAddresses();
    for (int i = 0; i < pinnedAddresses.size(); ++i) {
        std::cout << i << ": ";
        std::cout << pinnedAddresses[i] << std::endl;
    }
    std::cout << "Would you like to add new addresses?[y/N]" << std::endl;
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        std::cout << std::endl << "Write new address" << std::endl;
        std::string newAddress;
        std::cin >> newAddress;
        pinnedAddresses.push_back(newAddress);
        passenger.setPinnedAddresses(pinnedAddresses);
    }
}

void PassengerGateway::seeOrderHistory() {
    std::cout << "Here are your order history:"<<std::endl;
    std::vector<std::string> orderIds = passenger.getOrderHistory();
    std::vector<Order> orderHistory;
    for (int i = 0; i < orderIds.size(); ++i) {
        //TODO: find order by id
        std::cout << i << ": ";
        orderHistory[i].printForPassenger();
    }
    std::cout<<"Would you like to get bill for any ride?[y/N]"<<std::endl;
    char answer;
    std::cin >> answer;
    if (answer == 'y') {
        std::cout << std::endl << "Write the number of order" << std::endl;
        int number;
        std::cin >> number;
        if(number<0 || number >= orderIds.size()){
            std::cout<<"Something went wrong..."<<std::endl;
            return;
        }
        std::cout << "You spent " << passenger.getBill(orderHistory[number]) << " for this ride";
    }
}

PassengerGateway::PassengerGateway() {start();}

