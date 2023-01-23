cmake_minimum_required(VERSION 3.22)
project(client_deubg)

set(CMAKE_CXX_STANDARD 11)

add_executable(client_deubg Data.h Data.cpp SocketIO.cpp SocketIO.h DefaultIO.h DefaultIO.cpp ass1/Geometry.cpp ass1/Geometry.h client.cpp InputFile.cpp InputFile.h KnnClassification.h KnnClassification.cpp)
file(GLOB SRC_FILES
        "*.cpp" "*.h"
        )