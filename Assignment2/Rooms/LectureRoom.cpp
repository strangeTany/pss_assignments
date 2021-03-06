//
// Created by strangetany on 05.03.2021.
//

#include "LectureRoom.h"
Condition LectureRoom::getMicState() const {
    return micCondition;
}

void LectureRoom::setMicState(Condition micCondition) {
    LectureRoom::micCondition = micCondition;
}

LectureRoom::LectureRoom(int roomNumber, const std::string &name) : Room(roomNumber, name) {
    if (roomNumber == 108)
        micCondition = broken;
}

bool LectureRoom::open(const User & user) {
    return Room::open(user);
}
