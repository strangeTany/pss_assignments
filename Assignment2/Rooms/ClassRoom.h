//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_CLASSROOM_H
#define ASSIGNMENT2_CLASSROOM_H


#include "Room.h"

class ClassRoom : Room {
private:
    Condition projectorCondition = off;
    Level accessLevel = green;
public:
    Condition getProjectorCondition() const;
    bool open(const User &) override;

    void setProjectorCondition(Condition projectorCondition);

    ClassRoom(int roomNumber);
};


#endif //ASSIGNMENT2_CLASSROOM_H
