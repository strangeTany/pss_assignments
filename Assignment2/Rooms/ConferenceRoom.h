//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_CONFERENCEROOM_H
#define ASSIGNMENT2_CONFERENCEROOM_H


#include "Room.h"

class ConferenceRoom: Room {
private:
    bool busy;
    Condition tvCondition = off;
    Level accessLevel = green;
public:
    bool isBusy() const;

    void setBusy(bool busy);

    Condition getTvCondition() const;

    void setTvCondition(Condition tvCondition);

    bool open(const User &) override;

    ConferenceRoom(int roomNumber, const std::string &name);

    ConferenceRoom(int roomNumber);
};


#endif //ASSIGNMENT2_CONFERENCEROOM_H
