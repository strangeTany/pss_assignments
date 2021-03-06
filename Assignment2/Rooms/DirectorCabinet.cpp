//
// Created by strangetany on 05.03.2021.
//

#include "DirectorCabinet.h"

const std::vector<User*> &DirectorCabinet::getDropList() const {
    return dropList;
}

void DirectorCabinet::setDropList(std::vector<User*> dropList) {
    DirectorCabinet::dropList = dropList;
}

DirectorCabinet::DirectorCabinet(int roomNumber) : Room(roomNumber) {}

bool DirectorCabinet::open(const User & user) {
    return Room::open( user);
}
