//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_PROFESSOR_H
#define ASSIGNMENT2_PROFESSOR_H


#include "User.h"
#include "Admin.h"

class Professor:public User {
private:
    std::string subject;
    std::string favouriteTorture;
public:
    Professor(const std::string &name, const std::string &surname, Level accessLevel, const std::string &email,
              const std::string &subject, const std::string &favouriteTorture);

    const std::string &getSubject() const;

    void setSubject(const std::string &subject);

    const std::string &getFavouriteTorture() const;

    void setFavouriteTorture(const std::string &favouriteTorture);

    void fixDevice(Condition &condition) override;

    static void callAdmin(Admin, Condition&);

};


#endif //ASSIGNMENT2_PROFESSOR_H
