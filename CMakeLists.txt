cmake_minimum_required(VERSION 2.8.12.2)
project(ass4)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-std=c++11)
file(GLOB ass4
        "*.h"
        "*.cpp"
        )
add_executable(ass4 Server.cpp Server.h  KnnClassification.cpp KnnClassification.h InputFile.cpp InputFile.h ass1/Geometry.h ass1/Geometry.cpp DefaultIO.cpp DefaultIO.h Command.cpp Command.h Upload.cpp Upload.h run.cpp)
set(SOURCE_FILES ${SOURCE_FILES} ass4 ass1/Geometry.cpp ass1/Geometry.h)
file(GLOB SRC_FILES
        "*.cpp" "*.h"
        )
target_sources(ass4 PUBLIC
        ${SRC_FILES}
        )
