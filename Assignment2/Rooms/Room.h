//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_ROOM_H
#define ASSIGNMENT2_ROOM_H

#include "../AccessLevel.cpp"
#include "../Users/User.h"
#include <string>

enum Condition {
    on, off, broken
};

class Room {
private:
    int roomNumber;
    Level accessLevel;
    std::string name;
public:
    Room(int roomNumber);

    Room(int roomNumber, std::string name);


    int getRoomNumber() const;

    Level getAccessLevel() const;

    void changeAccessLevel(Level accessLevel);

    const std::string &getName() const;

    void setName(const std::string &name);

    virtual bool open(const User&);

};


#endif //ASSIGNMENT2_ROOM_H
