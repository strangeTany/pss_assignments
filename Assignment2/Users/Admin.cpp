//
// Created by strangetany on 05.03.2021.
//

#include <algorithm>
#include "Admin.h"
#include "../Rooms/Room.h"

void Admin::fixDevice(Condition &condition) {
    condition = on;
}

Admin::Admin(const std::string &name, const std::string &surname, const std::string &email) : User(name, surname,
                                                                                                   email) {}


void Admin::setSpecialAccess(std::string email, Room& room){
    room.specialAccess.push_back(email);
}
void Admin::removeSpecialAccess(std::string email, Room& room){
    room.specialAccess.erase(std::find(room.specialAccess.begin(), room.specialAccess.end()+1, email));
}