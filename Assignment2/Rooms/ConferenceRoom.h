//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_CONFERENCEROOM_H
#define ASSIGNMENT2_CONFERENCEROOM_H


#include "Room.h"

class ConferenceRoom:public Room {
private:
    bool busy;
    Condition tvCondition = off;
public:
    bool isBusy() const;

    void setBusy(bool busy);

    Condition getTvCondition() const;

    void setTvCondition(Condition tvCondition);

    ConferenceRoom(int roomNumber, int floor, const std::string &name);

};


#endif //ASSIGNMENT2_CONFERENCEROOM_H
