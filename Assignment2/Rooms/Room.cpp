//
// Created by strangetany on 05.03.2021.
//

#include "Room.h"

#include <utility>

int Room::getRoomNumber() const {
    return roomNumber;
}

Level Room::getAccessLevel() const {
    return accessLevel;
}

void Room::changeAccessLevel(Level accessLevel) {
    Room::accessLevel = accessLevel;
}

const std::string &Room::getName() const {
    return name;
}

void Room::setName(const std::string &name) {
    Room::name = name;
}

bool Room::open(const User& user) {
    switch(Room::getAccessLevel()){
        case no_level:
            return true;
        case green:
            return user.getAccessLevel()!=no_level;
        case yellow:
            return user.getAccessLevel()!=no_level && user.getAccessLevel()!=green;
        case red:
            return user.getAccessLevel()==red;
    }
}

Room::Room(int roomNumber) : roomNumber(roomNumber) {}

Room::Room(int roomNumber, std::string name) : roomNumber(roomNumber), name(std::move(name)) {}
