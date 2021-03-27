//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_LABEMPLOYEE_H
#define ASSIGNMENT2_LABEMPLOYEE_H


#include "User.h"

class LabEmployee:public User {
private:
    std::string education;
public:
    const std::string &getEducation() const;

    void setEducation(const std::string &education);

    LabEmployee(const std::string &name, const std::string &surname, Level accessLevel, const std::string &email,
                std::string education);
    void fixDevice(Condition &condition) override;
};


#endif //ASSIGNMENT2_LABEMPLOYEE_H
