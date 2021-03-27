#include <iostream>
#include "Users/Director.h"
#include "Users/Professor.h"
#include "Users/LabEmployee.h"
#include "Rooms/LectureRoom.h"
#include "Rooms/DirectorCabinet.h"
#include "Users/Guest.h"
#include "Rooms/ConferenceRoom.h"

int main() {
    Director director = *(new Director("Giancarlo", "Succi", "g.succi@innopolis.ru"));
    std::vector<User *> students;
    std::vector<LabEmployee> labEmployees;
    students.reserve(16);
for (int i = 0; i < 16; ++i) {
        students.push_back((director.createStudent(std::to_string(i).append("studentname"),
                                                    std::to_string(i).append("studentsurname"))));
    }
    labEmployees.reserve(8);
for (int i = 0; i < 8; ++i) {
        labEmployees.push_back(
                *new LabEmployee(std::to_string(i).append("employeename"), std::to_string(i).append("employeesurname"),
                                 yellow, std::to_string(i).append("email"), "none"));
    }
    Professor ITPProfessor = *(new Professor("Luiz", "Jonata", yellow, "l.jonata@innopolis.university",
                                             "Introduction to programming", "Written exam"));
    Professor CProfessor = *(new Professor("Ivan", "Konyukhov", yellow, "i.konyukhov@innopolis.university", "Calculus",
                                           "None, he is too kind for this"));
    Professor MAProfessor = *(new Professor("Sergey", "Gorodetskiy", yellow, "s.gorodetskiy@innopolis.ru",
                                            "Mathematical Analysis", "Here is your D"));
    Professor CAProfessor = *(new Professor("Artyom", "Burmyakov", yellow, "a.burmyakov@innopolis.university",
                                            "Computer Architecture", "See you on the retake"));
    Admin admin1 = *(new Admin("admin", "admin", "aaaa@innopolis.ru"));
    Admin admin2 = *(new Admin("nimda", "nimda", "nnnn@innopolis.ru"));

    Guest stupidChild("Who", "Cares", "w.cares@gmail.com");
    LectureRoom auditorium108 = *(new LectureRoom(108, 1, "East"));
    ConferenceRoom conferenceRoom1(312, 3, "Wave");
    ConferenceRoom conferenceRoom2(100, 1, "Fire");

    if(conferenceRoom2.open(stupidChild, false)){
        std::cout<< "I CAN DO THIS"<<std::endl;
    }
    if(!conferenceRoom1.open(stupidChild, false)){
        std::cout<<"WHY I CAN'T DO THIS"<<std::endl;
    }

    if(conferenceRoom1.open(stupidChild, true)) {
        std::cout << "NOW I CAN RUIN EVERYTHING IN THIS ROOM TOO" << std::endl;
    }
    std::cout<<std::boolalpha<<(bool)auditorium108.open(*students[0],false)<<std::endl;
    admin1.setSurname("hui");
    std::cout<<(Level)students[0]->getAccessLevel()<<std::endl;
    DirectorCabinet directorCabinet = *(new DirectorCabinet(666, 4));
    directorCabinet.setDropList(students);
    director.dropEverybody(directorCabinet.getDropList());
    std::cout<<students[0]->getAccessLevel()<<std::endl;
    std::vector<Room*> rooms = Room::getAllRooms();
    std::cout<<rooms.size();
    return 0;
}
