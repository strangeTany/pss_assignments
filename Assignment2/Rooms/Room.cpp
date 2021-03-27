//
// Created by strangetany on 05.03.2021.
//

#include "Room.h"
#include<algorithm>
#include <utility>
#include "../Users/Admin.h"

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

bool Room::open(const User &user, bool isEmergency) {
    if(isEmergency)
        return true;
    if (this->closed) {
        if (std::find(specialAccess.begin(), specialAccess.end(), user.getEmail()) != specialAccess.end()) {
            this->setClosed(false);
            return true;
        }
        if(user.getAccessLevel() >= this->getAccessLevel()) {
            this->setClosed(false);
            return true;
        }
    } else
        return true;
    return false;
}

Room::Room(int roomNumber, int floor, Level accessLevel) : roomNumber(roomNumber), floor(floor), accessLevel(accessLevel) {allRooms.push_back(this);}

Room::Room(int roomNumber, int floor, Level accessLevel, std::string name) : roomNumber(roomNumber), floor(floor), accessLevel(accessLevel), name(std::move(name)) {allRooms.push_back(this);}

int Room::getFloor() const {
    return floor;
}

void Room::setClosed(bool closed) {
    Room::closed = closed;
}

void Room::close() {
    setClosed(true);
}

Room::Room(int roomNumber, int floor, std::string name) : roomNumber(roomNumber), name(std::move(name)), floor(floor) {
    if(floor == 1)
        this->accessLevel = blue;
    else
        this->accessLevel = green;
}

const std::vector<Room *> &Room::getAllRooms() {
    return allRooms;
}
