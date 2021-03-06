//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_STUDENT_H
#define ASSIGNMENT2_STUDENT_H


#include "User.h"

class Student: User {
public:
    Student(const std::string &name, const std::string &surname, Level accessLevel, const std::string &email);
    void fixDevice(Condition& condition) override;
};


#endif //ASSIGNMENT2_STUDENT_H
