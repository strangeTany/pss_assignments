//
// Created by strangetany on 05.03.2021.
//

#include "ClassRoom.h"

Condition ClassRoom::getProjectorCondition() const {
    return projectorCondition;
}

void ClassRoom::setProjectorCondition(Condition projectorCondition) {
    ClassRoom::projectorCondition = projectorCondition;
}

ClassRoom::ClassRoom(int roomNumber) : Room(roomNumber) {}
