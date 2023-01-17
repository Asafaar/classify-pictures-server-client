//
// Created by asaf9 on 1/9/2023.
//
#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include "SocketIO.h"
#include <iostream>
using namespace std;
std::string SocketIO::read() {
    char clientInput[4096];
    int expected_data_len = sizeof(clientInput);
    int clientInputSize = recv(client_sock, clientInput, expected_data_len, 0);
    if (clientInputSize <= 0) {
        if (clientInputSize < 0) {
            perror("Error - Negative input!");
        }
    }
    return clientInput;
}

void SocketIO::write(std::string string) {
    send(client_sock, &string, string.length(), 0);
}

SocketIO::SocketIO(int sockNum) {
    this->client_sock = sockNum;
}


