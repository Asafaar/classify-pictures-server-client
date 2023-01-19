#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "../InputFile.h"
#include <string.h>
#include <fstream>
#include <algorithm>
#include "../SocketIO.h"
const string tempPort = "12346";

class path;

std::string convert_to_wsl_path(std::string windows_path) {
    std::string wsl_path = windows_path;
    string str = wsl_path.substr(0, 1);
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    string string2 = "/mnt/" + str;
    wsl_path.replace(0, 2, string2);
    return wsl_path;
}

//C:/Users/asaf9/OneDrive - Bar-Ilan University/Desktop/iris_classified.csv
std::string readFile2(string path) {
    string file_contents;
    char delimiter = ',';

    InputFile inputFile;
    file_contents = inputFile.readFile(path);
    return file_contents;

}
//C:/Users/asaf9/CLionProjects/ass4/files/iris_classified.csv
///mnt/c/Users/asaf9/CLionProjects/untitled95/files/beans_Classified.csv
using namespace std;

string UserSendFiles(string inputLine) {
    //InputFile inputFile;
//    inputLine= convert_to_wsl_path(inputLine);
//    if (!inputFile.CanReadFile(inputLine)){
//        return "input invalid";
//    } else{
    string string1 = readFile2(inputLine);
//    cout << string1 <<endl;
    return string1;
}

//C:/Users/asaf9/CLionProjects/client deubg/files/beans_Classified.csv
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
    auto* socketIo = new SocketIO(sock);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) { perror("error connecting to server"); }
    bool loadBool = false, downloadBool = false;
    while (true) {
        //char buffer[4096];
        //int expected_data_len = sizeof(buffer);
        //memset(buffer, 0, 4096);
        string currServerInput = socketIo->read();

        if (currServerInput != "done") {

            printf("%s\n", currServerInput.c_str());// currServerInput << endl;
            loadBool = UserLoadCommand(currServerInput);
            if (currServerInput == "get data") { downloadBool = true; }
            socketIo->write("ack");
            continue;
        }
        if (downloadBool) {
            string fileName = socketIo->read();
            socketIo->write("ack");
            std::ofstream myFile;
            myFile.open(fileName);
            while (true) {
                currServerInput = socketIo->read();
                if (currServerInput != "done") {
                    socketIo->write("ack");
                    myFile << currServerInput << "\n";
                    continue;
                }
                break;
            }
            myFile.close();
            continue;
        }
        string inputLine;
        getline(cin, inputLine);
        if (loadBool) {
            fstream file;
            //inputLine=UserSendFiles(inputLine);
            file.open(inputLine, ios::in);
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    socketIo->write(line);
                    /*
                    char *data_addr;
                    string str_obj(line);
                    data_addr = &str_obj[0];
                    int dataLen = line.size();
                    int sent_bytes = send(sock, data_addr, dataLen, 0);
                    if (sent_bytes < 0) {
                        perror("An error has occurred");
                    }
                     */
                    socketIo->read();
                    //recv(sock, buffer, expected_data_len, 0);
                    //../files/iris_Classified.csv
                    // ../files/iris_Unclassified.csv
                }
                file.close();
                loadBool = false;
                socketIo->write("done");
                socketIo->read();
                continue;
            }
        }
        char *data_addr;
        if (inputLine.empty()) {
            inputLine = "empty";
        }
        socketIo->write(inputLine);
        /*
        string str_obj(inputLine);
        data_addr = &str_obj[0];
        int dataLen = inputLine.size();
        int sent_bytes = send(sock, data_addr, dataLen, 0);
        if (sent_bytes < 0) {
            perror("An error has occurred");
        }
         */
    }
    close(sock);
    return 0;
}
