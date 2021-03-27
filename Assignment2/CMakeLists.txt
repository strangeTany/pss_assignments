cmake_minimum_required(VERSION 3.17)
project(Assignment2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assignment2 main.cpp Rooms/Room.cpp Rooms/Room.h AccessLevel.cpp Users/User.cpp Users/User.h Rooms/ClassRoom.cpp Rooms/ClassRoom.h Rooms/LectureRoom.cpp Rooms/LectureRoom.h Rooms/ConferenceRoom.cpp Rooms/ConferenceRoom.h Rooms/Cabinet.cpp Rooms/Cabinet.h Rooms/DirectorCabinet.cpp Rooms/DirectorCabinet.h Users/Professor.cpp Users/Professor.h Users/Student.cpp Users/Student.h Users/Director.cpp Users/Director.h Users/LabEmployee.cpp Users/LabEmployee.h Users/Admin.cpp Users/Admin.h Users/Guest.cpp Users/Guest.h)