//
// Created by strangetany on 05.03.2021.
//

#include <algorithm>
#include "Cabinet.h"

const std::vector<User> &Cabinet::getEmployees() const {
    return employees;
}

void Cabinet::setEmployees(const std::vector<User> &employees) {
    Cabinet::employees = employees;
}

void Cabinet::addAccess(const User& user) { employees.push_back(user); }

bool Cabinet::open(const User &user) {
    return (std::find(employees.begin(), employees.end(), user) != employees.end());
}