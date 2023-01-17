//
// Created by asaf9 on 1/9/2023.
//
#include "DefaultIO.h"
#include <iostream>
using namespace std;
std::string DefaultIO::read() {
    std::string str;
    char clientInput[4096];
    int expected_data_len = sizeof(clientInput);
    int clientInputSize = recv(client_sock, clientInput, expected_data_len, 0);
    if (clientInputSize <= 0) {
        if (clientInputSize < 0) {
            perror("Error - Negative input!");
            continue;
        }
    }
    return str;
}

void DefaultIO::write(std::string string) {
    std::cout <<string<<std::endl;
}


