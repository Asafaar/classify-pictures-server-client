cmake_minimum_required(VERSION 2.8.12.2)
project(Ass3)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-std=c++11)
add_executable(Ass3 Server.cpp Server.h  KnnClassification.cpp KnnClassification.h InputFile.cpp InputFile.h ass1/Geometry.h ass1/Geometry.cpp)
set(SOURCE_FILES ${SOURCE_FILES} ass1/Geometry.cpp ass1/Geometry.h)
