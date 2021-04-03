//
// Created by strangetany on 05.03.2021.
//

#ifndef ASSIGNMENT2_ROOM_H
#define ASSIGNMENT2_ROOM_H

#ifndef CONDITION
#define CONDITION
enum Condition {
    on, off, broken
};
#endif

#include "../AccessLevel.cpp"
#include "../Users/User.h"
#include <string>
#include <vector>

class User;
class Room {
protected:
    Room(int roomNumber, int floor, Level accessLevel);

    Room(int roomNumber, int floor, Level accessLevel, std::string name);

    void setClosed(bool closed);

    inline static std::vector<Room*> allRooms;

private:
    int roomNumber;
    Level accessLevel;
    std::string name;
    bool closed = true;
    int floor;
public:
    std::vector<std::string> specialAccess;

    Room(int roomNumber, int floor, std::string name);

    int getRoomNumber() const;

    Level getAccessLevel() const;

    void changeAccessLevel(Level accessLevel);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getFloor() const;

    virtual bool open(const User&, bool isEmergency);

    virtual void close();

    static const std::vector<Room *> &getAllRooms();

};


#endif //ASSIGNMENT2_ROOM_H
