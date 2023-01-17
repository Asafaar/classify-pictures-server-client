//
// Created by asaf9 on 1/17/2023.
//

#include "CLI.h"
#include "Upload.h"
#include "AlgoSettings.h"
#include "ClassifyData.h"
#include "DisplayResults.h"
#include "DownloadResults.h"

void CLI::start() {
    while (true) {
        for (int i = 0; i < 5; ++i) {
            int j = i + 1;
            std::string s = std::to_string(j);
            std::string string = s + ". " + command[i]->description;
            command[0]->dio.write(string);
        }
        command[0]->dio.write("8. exit");
        std::string string = command[0]->dio.read();
        int UserSelect = stoi(string);
        UserSelect -= 1;
        if (UserSelect == 8) {
            exit(1);
        }
        command[UserSelect]->execute();
    }
}

CLI::CLI(Data* data, DefaultIO* defaultIo1) {
    this->data=data;
    this->defaultIo=defaultIo1;
    this->command[0] = new Upload(data,*defaultIo1);
    this->command[1] = new AlgoSettings(data,*defaultIo1);
    this->command[2] = new ClassifyData(data,*defaultIo1);
    this->command[3] = new DisplayResults(data, *defaultIo1);
    this->command[4] = new DownloadResults(data,*defaultIo1);
}

