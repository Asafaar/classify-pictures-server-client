#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "../SocketIO.h"
#include <thread>
#include <mutex>

const std::string tempPort = "12346";
class path;

using namespace std;
std::mutex mtx;

/*
../files/wine_Classified.csv
../files/wine_UnClassified.csv
../files/data.csv
*/

void sendFile(SocketIO *socketIo, string inputLine) {
    std::fstream filePath(inputLine);
    while(!filePath.good()) {
        printf("The file doesn't exist!\nEnter a new path:\n");
        getline(cin, inputLine);
        filePath.open(inputLine);
    }
    std::fstream file;
    file.open(inputLine, ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            socketIo->write(line);
            socketIo->read();
        }
        filePath.close();
        socketIo->write(socketIo->sendAnswer);
    }
    return;
}

void createFile(SocketIO *socketIo, string fileName) {
    FILE* file = fopen(fileName.c_str(), "w");;
    while(!file) {
        printf("Tha path isn't valid! Enter a new one:\n");
        getline(cin, fileName);
        file = fopen(fileName.c_str(), "w");
    }
    fclose(file);
    std::fstream myFile;
    myFile.open(fileName, ios::out);
    string currServerInput;
    if (myFile.is_open()) {
        while (true) {
            currServerInput = socketIo->read();
            if (currServerInput != socketIo->sendAnswer) {
                socketIo->write(socketIo->gotMessage);
                myFile << currServerInput;
                continue;
            }
            socketIo->write(socketIo->gotMessage);
            break;
        }
        myFile.close();
        return;
    }
}

bool UserLoadCommand(string buffer) {
    if (buffer == "Please upload your local train CSV file" or
        buffer == "Upload complete\nPlease upload your local test CSV file") {
        return true;
    } else return false;
}

int port_no = 0;

void socketforfile(const char *ip_address, int serverPort, string filename) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("error creating socket"); }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no + 1);
    auto *socketIo = new SocketIO(sock);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) { perror("error connecting to server"); }
    char clientInput[4096];
    memset(clientInput, '\0', 4096);
    // Get info from client
    createFile(socketIo, filename);
    return;

}

int main(int argc, char *argv[]) {
    const char *ip_address;
//    const char *ip_address = "127.0.0.1"; for bebug
    if (argc != 3) {
        cout << "Need enter valid Ip and port" << endl;
        return -1;
    }
    ip_address = argv[1];
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int serverPort = std::stoi(argv[2]);
    port_no = serverPort;
    if (sock < 0) {
        perror("error creating socket");
        return -1;
    }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(serverPort);
    auto *socketIo = new SocketIO(sock);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        return -1;
    }
    bool loadBool = false, downloadBool = false;
    while (true) {
        string currServerInput = socketIo->read();
        if (currServerInput == socketIo->terminateClient) { break; }
        // If the server wishes to get an answer, skip and send the answer
        if (currServerInput != socketIo->sendAnswer) {
            printf("%s\n", currServerInput.c_str());
            //cout << currServerInput << endl;
            loadBool = UserLoadCommand(currServerInput);
            if (currServerInput == "Enter path") {
                downloadBool = true;
            }
            socketIo->write(socketIo->gotMessage);
            continue;
        }
        string inputLine;
        getline(cin, inputLine);
        // Client wants to download a file

        if (downloadBool) {
            std::thread t1(socketforfile, ip_address, serverPort, inputLine);
            downloadBool = false;
            t1.join();
            continue;
        }
        // Client wants to send files to the server
        if (loadBool) {
            sendFile(socketIo, inputLine);
            loadBool = false;
            continue;
        }
        socketIo->write(inputLine);
    }
    close(sock);
}
//../files/iris_classified.csv
//../files/iris_Unclassified.csv

