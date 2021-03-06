//
// Created by strangetany on 05.03.2021.
//

#include <iostream>
#include "Director.h"

void Director::dropEverybody(std::vector<User*> dropList) {
    for (auto & i : dropList) {
        i -> setAccessLevel(no_level);
    }
}
Student * Director::createStudent(std::string name, std::string surname) {
    std::string email= name.substr(0,1).append(".").append(surname).append("@innopolis.university");
    return new Student(name,surname,green, email);
}

Director::Director(const std::string &name, const std::string &surname, const std::string &email) : User(name, surname,
                                                                                                         email) {}

void Director::fixDevice(Condition &condition) {
    std::cout<<"do nothing"<<std::endl;

}
