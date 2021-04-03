//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_ADMIN_H
#define ASSIGNMENT2_ADMIN_H


#include "User.h"

class Admin: public User {
private:
    Level accessLevel = red;
public:
    void fixDevice(Condition &condition) override;

    Admin(const std::string &name, const std::string &surname, const std::string &email);

    static void setSpecialAccess(std::string email, Room& room);

    void removeSpecialAccess(std::string email, Room &room);

    void endOfEmergency(){
        std::vector<Room*> rooms = Room::getAllRooms();
        for(auto r: rooms){
            r->close();
        }
    }
};


#endif //ASSIGNMENT2_ADMIN_H
