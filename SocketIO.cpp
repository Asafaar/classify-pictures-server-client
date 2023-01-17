//
// Created by asaf9 on 1/9/2023.
//
#include <cstdio>
#include <sys/socket.h>
#include "SocketIO.h"
#include <bits/stdc++.h>
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

void SocketIO::write(std::string str) {
    char arr[str.length() + 1];
    strcpy(arr, str.c_str());
    send(client_sock, arr, str.length() + 1, 0);
}

SocketIO::SocketIO(int sockNum) {
    this->client_sock = sockNum;
}


