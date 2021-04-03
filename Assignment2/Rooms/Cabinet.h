//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_CABINET_H
#define ASSIGNMENT2_CABINET_H


#include <vector>
#include "Room.h"

class Cabinet: public Room {
private:
    std::vector<User*> employees;
public:
    const std::vector<User*> &getEmployees() const;

    void setEmployees(const std::vector<User*> &employees);

    void addAccess(User *);

    Cabinet(int roomNumber, int floor, std::vector<User*> employees);

    bool open(const User&, bool isEmergency) override;
};


#endif //ASSIGNMENT2_CABINET_H
