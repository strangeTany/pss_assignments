//
// Created by strangetany on 05.03.2021.
//

#include <iostream>
#include "Student.h"



void Student::fixDevice(Condition& condition) {
    if(condition==off)
        condition=on;
    if(condition==broken)
        std::cout << "sad((("<<std::endl;

}

Student::Student(const std::string &name, const std::string &surname, Level accessLevel, const std::string &email)
        : User(name, surname, accessLevel, email) {}
