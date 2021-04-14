//
// Created by strangetany on 13.04.2021.
//

#ifndef ASSIGNMENT4_DATABASE_H
#define ASSIGNMENT4_DATABASE_H

#include <fstream>
#include <vector>

template <typename T>
class DataBase {
    std::fstream DB;
public:
   DataBase(const std::string& DBName);
   T* find(const std::string& id);
   bool add(std::string newObject);
   std::vector<T> returnAll();

    DataBase();
};




#endif //ASSIGNMENT4_DATABASE_H
