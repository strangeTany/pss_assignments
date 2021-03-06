//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_LECTUREROOM_H
#define ASSIGNMENT2_LECTUREROOM_H


#include "Room.h"

class LectureRoom : Room {
private:
    Level accessLevel = yellow;
    Condition micCondition = off;
public:
    Condition getMicState() const;

    void setMicState(Condition micCondition);

    LectureRoom(int roomNumber, const std::string &name);
};


#endif //ASSIGNMENT2_LECTUREROOM_H
