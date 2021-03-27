//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_LECTUREROOM_H
#define ASSIGNMENT2_LECTUREROOM_H


#include "Room.h"

class LectureRoom :public Room {
private:
    Condition micCondition = off;
public:
    Condition getMicState() const;

    void setMicState(Condition micCondition);

    LectureRoom(int roomNumber, int floor, const std::string &name);
};


#endif //ASSIGNMENT2_LECTUREROOM_H
