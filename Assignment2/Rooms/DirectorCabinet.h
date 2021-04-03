//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_DIRECTORCABINET_H
#define ASSIGNMENT2_DIRECTORCABINET_H


#include <vector>
#include "Room.h"
#include "../Users/Student.h"

class DirectorCabinet:public Room {
private:
    std::vector<User*> dropList;
public:
    const std::vector<User*> &getDropList() const;

    void setDropList(std::vector<User*> dropList);

    DirectorCabinet(int roomNumber, int floor);
};


#endif //ASSIGNMENT2_DIRECTORCABINET_H
