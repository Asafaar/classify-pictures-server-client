//#include <iostream>
//#include <sys/socket.h>
//#include <stdio.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <unistd.h>
//#include <string.h>
//#include <fstream>
//#include "../SocketIO.h"
//
//const std::string tempPort = "12346";
//class path;
//using namespace std;
//
//void sendFile(SocketIO *socketIo, string inputLine) {
//    fstream file;
//    file.open(inputLine, ios::in);
//    bool goodpath=file.is_open();
//    if (goodpath) {
//        string line;
//        while (getline(file, line)) {
//            socketIo->write(line);
//            socketIo->read();
//        }
//        file.close();
//        socketIo->write(socketIo->sendAnswer);
//        socketIo->read();
//    }
//    else {
//            return;
//    }
//    return;
//}
//
//void createFile(SocketIO *socketIo) {
//    cout << "1" << endl;
//    string fileName = socketIo->read(), currServerInput;
//    cout << "2" << endl;
//    socketIo->write(socketIo->gotMessage);
//    cout << "3" << endl;
//    std::ofstream myFile;
//    cout << "4" << endl;
//    myFile.open(fileName);
//    cout << "5" << endl;
//
//    while (true) {
//        currServerInput = socketIo->read();
//        if (currServerInput != socketIo->sendAnswer) {
//            socketIo->write(socketIo->gotMessage);
//            myFile << currServerInput;
//            continue;
//        }
//        cout << "6" << endl;
//        socketIo->write(socketIo->gotMessage);
//        break;
//    }
//    cout << "7" << endl;
//    myFile.close();
//    return;
//    //../files/wine_classified.csv
//    //../files/wine_unclassified.csv
//}
//
//bool UserLoadCommand(string buffer) {
//    if (buffer == "Please upload your local train CSV file" or
//        buffer == "Upload complete\nPlease upload your local test CSV file") {
//        return true;
//    } else return false;
//}
//
//const int port_no = 12346;
//
//int main(int argc, char *argv[]) {
//    const char *ip_address;
////    const char *ip_address = "127.0.0.1"; for bebug
//    if (argc!=3){
//        cout << "Need enter valid Ip and port" << endl;
//        return -1;
//    }
//    ip_address=argv[1];
//    int serverPort = std::stoi(argv[2]);
//    int sock = socket(AF_INET, SOCK_STREAM, 0);
//    if (sock < 0) { perror("error creating socket"); return -1;}
//    struct sockaddr_in sin;
//    memset(&sin, 0, sizeof(sin));
//    sin.sin_family = AF_INET;
//    sin.sin_addr.s_addr = inet_addr(ip_address);
//    sin.sin_port = htons(serverPort);
//    auto *socketIo = new SocketIO(sock);
//    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) { perror("error connecting to server"); return -1; }
//    bool loadBool = false, downloadBool = false;
//    while (true) {
//        string currServerInput = socketIo->read();
//        if (currServerInput == socketIo->terminateClient) { break; }
//        // If the server wishes to get an answer, skip and send the answer
//        if (currServerInput != socketIo->sendAnswer) {
//            printf("%s\n", currServerInput.c_str());
//            loadBool = UserLoadCommand(currServerInput);
//            if (currServerInput == "Enter path") { downloadBool = true; }
//            socketIo->write(socketIo->gotMessage);
//            continue;
//        }
//        string inputLine;
//        getline(cin, inputLine);
//        // Client wants to download a file
//        if (downloadBool) {
//            socketIo->write(inputLine);
//            createFile(socketIo);
//            downloadBool = false;
//            continue;
//        }
//        // Client wants to send files to the server
//        if (loadBool) {
//            sendFile(socketIo, inputLine);
//            loadBool = false;
//            continue;
//        }
//        socketIo->write(inputLine);
//    }
//    close(sock);
//    //return 0;
//}
