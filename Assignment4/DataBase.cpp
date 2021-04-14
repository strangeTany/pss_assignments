//
// Created by strangetany on 13.04.2021.
//

#include <sstream>
#include "DataBase.h"

template<typename T>
DataBase<T>::DataBase(const std::string &DBName):DB(std::fstream(DBName + ".txt")) {}

template<typename T>
T* DataBase<T>::find(const std::string &id) {
    std::string line;
    while (std::getline(DB, line)) {
        auto iss = std::istringstream(line);
        auto idFile = std::string();
        iss >> idFile;
        if (id == idFile) {
            T* t;
            return t -> serialize(line);
        }
    }
    return nullptr;
}

template<typename T>
bool DataBase<T>::add(std::string newObject) {
    std::fstream tmpFile("tmp.txt");
    std::string line;
    auto newObjectId = std::string();
    auto iss1 = std::istringstream(newObject);
    iss1 >> newObjectId;
    while (std::getline(DB, line)) {
        auto iss = std::istringstream(line);
        auto idFile = std::string();
        iss >> idFile;
        if (newObjectId == idFile)
            tmpFile << newObject;
        else
            tmpFile << line;
    }
    return true;
}

template<typename T>
std::vector<T> DataBase<T>::returnAll() {
    std::vector<T> allData;
    std::string line;
    while (std::getline(DB, line)) {
        T tmpObject;
        tmpObject.serialize(line);
        allData.push_back(tmpObject);
    }
    return allData;
}

template<typename T>
DataBase<T>::DataBase() {}


