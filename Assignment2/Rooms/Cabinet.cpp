//
// Created by strangetany on 05.03.2021.
//

#include <algorithm>
#include <utility>
#include "Cabinet.h"

const std::vector<User*> &Cabinet::getEmployees() const {
    return employees;
}

void Cabinet::setEmployees(const std::vector<User*> &employees) {
    Cabinet::employees = employees;
}

void Cabinet::addAccess(User * user) { employees.push_back(user); }

bool Cabinet::open(const User &user, bool isEmergency) {
    if(isEmergency)
        return true;
    for (auto & employee : employees) {
        if(*employee == user)
            return true;
    }
    return false;
}

Cabinet::Cabinet(int roomNumber, int floor, std::vector<User*> employees) : Room(roomNumber,
                                                                                                          floor,
                                                                                                          red),
                                                                                                     employees(std::move(
                                                                                                             employees)) {}
