//
// Created by asaf9 on 1/9/2023.
//
#include <iostream>
#include "StandareIO.h"
using namespace std;
std::string DefaultIO::read() {
    std::string str;
    std::getline(std::cin, str);
    return str;
}

void DefaultIO::write(std::string string) {
    std::cout <<string<<std::endl;
}