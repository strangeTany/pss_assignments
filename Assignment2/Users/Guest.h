//
// Created by strangetany on 20.03.2021.
//

#ifndef ASSIGNMENT2_GUEST_H
#define ASSIGNMENT2_GUEST_H


#include "User.h"

class Guest: public User {
public:
    Guest(const std::string &name, const std::string &surname, const std::string &email);
    void doNothing();
    void fixDevice(Condition &condition) override;
};


#endif //ASSIGNMENT2_GUEST_H
