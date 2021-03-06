//
// Created by strangetany on 05.03.2021.
//

#include "LabEmployee.h"

#include <utility>

const std::string &LabEmployee::getEducation() const {
    return education;
}

void LabEmployee::setEducation(const std::string &education) {
    LabEmployee::education = education;
}

LabEmployee::LabEmployee(const std::string &name, const std::string &surname, Level accessLevel,
                         const std::string &email, std::string education) : User(name, surname, accessLevel,
                                                                                        email), education(std::move(education)) {}

void LabEmployee::fixDevice(Condition &condition) {
    condition=on;

}
