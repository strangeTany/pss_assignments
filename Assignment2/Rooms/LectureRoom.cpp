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

LectureRoom::LectureRoom(int roomNumber, int floor, const std::string &name) : Room(roomNumber, floor,blue, name) {
    if (roomNumber == 108)
        micCondition = broken;
}

