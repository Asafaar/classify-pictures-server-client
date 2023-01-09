//
// Created by asaf9 on 1/9/2023.
//
#include <iostream>
#include "StandareIO.h"
using namespace std;
std::string read() {
    std::string string;
    std::cin >> string;
    return string;
}

void write(std::string string) {
    std::cout <<string<<std::endl;
}