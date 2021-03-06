//
// Created by strangetany on 05.03.2021.
//

#include "Admin.h"

void Admin::fixDevice(Condition &condition) {
    condition = on;
}

Admin::Admin(const std::string &name, const std::string &surname, const std::string &email) : User(name, surname,
                                                                                                   email) {}
