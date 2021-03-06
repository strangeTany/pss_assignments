//
// Created by strangetany on 05.03.2021.
//

#include "User.h"

#include <utility>

const std::string &User::getName() const {
    return name;
}

void User::setName(const std::string &name) {
    User::name = name;
}

const std::string &User::getSurname() const {
    return surname;
}

void User::setSurname(const std::string &surname) {
    User::surname = surname;
}

Level User::getAccessLevel() const {
    return accessLevel;
}

void User::setAccessLevel(Level accessLevel) {
    User::accessLevel = accessLevel;
}

const std::string &User::getEmail() const {
    return email;
}

void User::setEmail(const std::string &email) {
    User::email = email;
}

User::User(std::string name, std::string surname, Level accessLevel, std::string email) : name(std::move(
        name)), surname(std::move(surname)), accessLevel(accessLevel), email(std::move(email)) {}

User::User(std::string name, std::string surname, std::string email) : name(std::move(name)),
                                                                                            surname(std::move(surname)),
                                                                                            email(std::move(email)) {}
