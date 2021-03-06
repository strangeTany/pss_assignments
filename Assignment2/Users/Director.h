//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_DIRECTOR_H
#define ASSIGNMENT2_DIRECTOR_H


#include <vector>
#include "User.h"
#include "Student.h"

class Director : User {
private:
    Level accessLevel = red;
public:
    void dropEverybody(std::vector<User>);
    Student * createStudent(std::string, std::string);

    Director(const std::string &name, const std::string &surname, const std::string &email);
};


#endif //ASSIGNMENT2_DIRECTOR_H
