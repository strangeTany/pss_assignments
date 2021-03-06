//
// Created by strangetany on 05.03.2021.
//

#include <iostream>
#include "Professor.h"

Professor::Professor(const std::string &name, const std::string &surname, Level accessLevel, const std::string &email,
                     const std::string &subject, const std::string &favouriteTorture) : User(name, surname, accessLevel,
                                                                                             email), subject(subject),
                                                                                        favouriteTorture(
                                                                                                favouriteTorture) {}

const std::string &Professor::getSubject() const {
    return subject;
}

void Professor::setSubject(const std::string &subject) {
    Professor::subject = subject;
}

const std::string &Professor::getFavouriteTorture() const {
    return favouriteTorture;
}

void Professor::setFavouriteTorture(const std::string &favouriteTorture) {
    Professor::favouriteTorture = favouriteTorture;
}

void Professor::fixDevice(Condition &condition) {
    std::cout<<"There is nothing I can do here";
}

void Professor::callAdmin(Admin admin, Condition &condition) {
    admin.fixDevice(condition);
}
