//
// Created by strangetany on 05.03.2021.
//

#include "ConferenceRoom.h"

bool ConferenceRoom::isBusy() const {
    return busy;
}

void ConferenceRoom::setBusy(bool busy) {
    ConferenceRoom::busy = busy;
}

Condition ConferenceRoom::getTvCondition() const {
    return tvCondition;
}

void ConferenceRoom::setTvCondition(Condition tvCondition) {
    ConferenceRoom::tvCondition = tvCondition;
}

ConferenceRoom::ConferenceRoom(int roomNumber) : Room(roomNumber) {busy= false;}

ConferenceRoom::ConferenceRoom(int roomNumber, const std::string &name) : Room(roomNumber, name) {busy= false;}

bool ConferenceRoom::open(const User & user) {
    return Room::open(user);
}
