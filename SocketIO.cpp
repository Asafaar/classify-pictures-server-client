//
// Created by asaf9 on 1/9/2023.
//
#include <cstdio>
#include <sys/socket.h>
#include "SocketIO.h"
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

std::string SocketIO::read() {
    char clientInput[4096]={0};
    int expected_data_len = sizeof(clientInput);
    int clientInputSize = recv(client_sock, clientInput, expected_data_len, 0);

    if (clientInputSize < 0) {
        perror("Error - Negative input!");
    }
    string str = clientInput;
    return str;
}

void SocketIO::write(std::string str) {
    int arrSize = str.length() + 1;
    char arr[arrSize];
    strcpy(arr, str.c_str());
    send(client_sock, arr, arrSize, 0);
}

SocketIO::SocketIO() {
    this->client_sock = 0;
}

SocketIO::SocketIO(int sockNum) {
    this->client_sock = sockNum;
}


