//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_USER_H
#define ASSIGNMENT2_USER_H


#include <string>
#include "../AccessLevel.cpp"
#include "../Rooms/Room.h"

class User {

private:
    std::string name;
    std::string surname;
    Level accessLevel;
    std::string email;
public:
    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getSurname() const;

    void setSurname(const std::string &surname);

    Level getAccessLevel() const;

    void setAccessLevel(Level accessLevel);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    virtual void fixDevice(Condition& condition)=0;

    bool operator==(const User&);

    User(std::string name, std::string surname, Level accessLevel, std::string email);

    User(std::string name, std::string surname, std::string email);

    User(std::string name, std::string surname);

    void emergency() const;

};


#endif //ASSIGNMENT2_USER_H
