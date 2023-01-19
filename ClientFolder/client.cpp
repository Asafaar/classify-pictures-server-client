#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <algorithm>
#include "../SocketIO.h"

const std::string tempPort = "12346";
class path;
using namespace std;

void sendFile(SocketIO *socketIo, string inputLine) {
    fstream file;
    file.open(inputLine, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            socketIo->write(line);
            socketIo->read();
        }
        file.close();
        socketIo->write(socketIo->sendAnswer);
        socketIo->read();
    }
    return;
}

void createFile(SocketIO *socketIo) {
    string fileName = socketIo->read(), currServerInput;
    socketIo->write(socketIo->gotMessage);
    std::ofstream myFile;
    myFile.open(fileName);
    while (true) {
        currServerInput = socketIo->read();
        if (currServerInput != socketIo->sendAnswer) {
            socketIo->write(socketIo->gotMessage);
            myFile << currServerInput << "\n";
            continue;
        }
        break;
    }
    myFile.close();
    return;
}

bool UserLoadCommand(string buffer) {
    if (buffer == "Please upload your local train CSV file" or
        buffer == "Upload complete\nPlease upload your local test CSV file") {
        return true;
    } else return false;
}

const int port_no = 12346;

int main(int argc, char *argv[]) {
    int serverPort = std::stoi(tempPort);
    const char *ip_address = "127.0.0.1";
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("error creating socket"); }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    auto *socketIo = new SocketIO(sock);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) { perror("error connecting to server"); }
    bool loadBool = false, downloadBool = false;
    while (true) {
        string currServerInput = socketIo->read();
        if (currServerInput == socketIo->terminateClient) { break; }
        // If the server wishes to get an answer, skip and send the answer
        if (currServerInput != socketIo->sendAnswer) {
            printf("%s\n", currServerInput.c_str());
            loadBool = UserLoadCommand(currServerInput);
            if (currServerInput == "get data") { downloadBool = true; }
            socketIo->write(socketIo->gotMessage);
            continue;
        }
        // Client wants to download a file
        if (downloadBool) {
            createFile(socketIo);
            downloadBool = false;
            continue;
        }
        string inputLine;
        getline(cin, inputLine);
        // Client wants to send files to the server
        if (loadBool) {
            sendFile(socketIo, inputLine);
            loadBool = false;
            continue;
        }
        socketIo->write(inputLine);
    }
    close(sock);
    return 0;
}
