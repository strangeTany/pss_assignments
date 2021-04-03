//
// Created by strangetany on 20.03.2021.
//

#include <iostream>
#include "Guest.h"

Guest::Guest(const std::string &name, const std::string &surname, const std::string &email) : User(
        name, surname, blue, email) {}

void Guest::doNothing() {
    std::cout<<"Let's look at students as at animals in zoo";
}

void Guest::fixDevice(Condition &condition) {
    std::cout<<"I have no rights to do anything";
}
