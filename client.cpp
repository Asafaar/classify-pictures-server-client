#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
    const char *ip_address = "127.0.0.1";
    const string tempPort = "12345";
    const int port_no = std::stoi(tempPort);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("error creating socket"); }
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) { perror("error connecting to server"); }
    while (true) {
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        //memset(buffer, 0, 4096);
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        //if (strcmp(buffer, "done") == 0) { break; }
        cout << buffer << endl;

        if (read_bytes == 0) {
            perror("connection is closed");
        } else if (read_bytes < 0) { perror("Error while reading input!"); }
        string inputLine;
        getline(cin, inputLine);
        char *data_addr;
        string str_obj(inputLine);
        data_addr = &str_obj[0];
        int dataLen = inputLine.size();
        int sent_bytes = send(sock, data_addr, dataLen, 0);
        if (sent_bytes < 0) {
            perror("An error has occured");
        }
    }
    close(sock);
    return 0;
}