//
// Created by asaf9 on 1/9/2023.
//
#include <iostream>
#include "StandareIO.h"
#include "DefaultIO.h"
using namespace std;
std::string DefaultIO::read() {
    std::string string;
    std::cin >> string;
    return string;
}

void DefaultIO::write(std::string string) {
    std::cout <<string<<std::endl;
}