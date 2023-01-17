//
// Created by asaf9 on 1/9/2023.
//
#include "Upload.h"
#include "Command.h"
#include "DownloadResults.h"
#include "ClassifyData.h"
#include <iostream>
#include "DisplayResults.h"
#include "AlgoSettings.h"
#include "CLI.h"
using std::cout;

void run() {
    Data data;
    StandareIO standareIo;
    CLI cli=CLI(&data,&standareIo);
    cli.start();



//    Data data;
//    Upload upload(&data);
//    AlgoSettings algoSettings(&data);
//    DisplayResults displayResults(&data, DefaultIO());
//    DownloadResults downloadResults(&data);
//    ClassifyData classifyData(&data);
//
//    Command *command[5];
//    command[0] = new Upload(&data);
//    command[1] = new AlgoSettings(&data);
//    command[2] = new ClassifyData(&data);
//    command[3] = new DisplayResults(&data, DefaultIO());
//    command[4] = new DownloadResults(&data);
//    ={upload,algoSettings,classifyData,displayResults,downloadResults};
//    while (true) {
//        for (int i = 0; i < 5; ++i) {
//            int j = i + 1;
//            std::string s = std::to_string(j);
//            std::string string = s + ". " + command[i]->description;
//            command[0]->dio.write(string);
//        }
//        command[0]->dio.write("8. exit");
//        std::string string = command[0]->dio.read();
//        int UserSelect = stoi(string);
//        UserSelect -= 1;
//        if (UserSelect == 8) {
//            exit(1);
//        }
//        command[UserSelect]->execute();
//    }

}