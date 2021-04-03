//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_CLASSROOM_H
#define ASSIGNMENT2_CLASSROOM_H


#include "Room.h"

class ClassRoom :public Room {
private:
    Condition projectorCondition = off;
public:
    Condition getProjectorCondition() const;

    void setProjectorCondition(Condition projectorCondition);

    ClassRoom(int roomNumber, int floor);
};


#endif //ASSIGNMENT2_CLASSROOM_H
