#include <iostream>
#include "Users/Director.h"
#include "Users/Professor.h"
#include "Users/LabEmployee.h"
#include "Rooms/LectureRoom.h"
#include "Rooms/DirectorCabinet.h"

int main() {
    Director director = *(new Director("Giancarlo", "Succi", "g.succi@innopolis.ru"));
    std::vector<User *> students;
    std::vector<LabEmployee> labEmployees;
    for (int i = 0; i < 16; ++i) {
        students.push_back((director.createStudent(std::to_string(i).append("studentname"),
                                                    std::to_string(i).append("studentsurname"))));
    }
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

    LectureRoom auditorium108 = *(new LectureRoom(108, "East"));
    if(auditorium108.open(*students[0])){
        std::cout<<"closed("<<std::endl;
    }
    std::cout<<students[0]->getAccessLevel()<<std::endl;
    DirectorCabinet directorCabinet = *(new DirectorCabinet(666));
    directorCabinet.setDropList(students);
    director.dropEverybody(directorCabinet.getDropList());
    std::cout<<students[0]->getAccessLevel()<<std::endl;
    return 0;
}
