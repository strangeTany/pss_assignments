//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_CABINET_H
#define ASSIGNMENT2_CABINET_H


#include <vector>
#include "Room.h"

class Cabinet: Room {
private:
    std::vector<User> employees;
    Level accessLevel = yellow;
public:
    const std::vector<User> &getEmployees() const;

    void setEmployees(const std::vector<User> &employees);

    void addAccess(const User&);

    bool open(const User&) override;
};


#endif //ASSIGNMENT2_CABINET_H
