/**
 * The class in charge of running the program.
 */

#include <thread>
#include "CLI.h"
#include "Upload.h"
#include "AlgoSettings.h"
#include "ClassifyData.h"
#include "DisplayResults.h"
#include "DownloadResults.h"
#include "mutex"

/**
 * Start running the program.
 */
void CLI::start() {
    std::mutex mtx;
    // Keep letting the client choose an option
    while (true) {
        std::string menu = "";
        // Concatenate all command descriptions
        for (int i = 0; i < 5; ++i) {
            int j = i + 1;
            menu += std::to_string(j) + ". " + command[i]->description + "\n";
        }
        menu += "8. exit";
        // send to the client
        command[0]->dio->write(menu);
        command[0]->dio->read();
        command[0]->dio->write(command[0]->dio->sendAnswer);
        std::string userChoice = command[0]->dio->read();
        // Make sure input is a digit
        if (!std::isdigit(userChoice[0]) || userChoice.length() != 1) {
            command[0]->dio->write("Invalid input!\nTry again:");
            command[0]->dio->read();
            continue;
        }
        int UserSelect = stoi(userChoice);
        UserSelect -= 1;

        // Choice == 8 -> close client socket
        if (UserSelect == 7) {
            command[0]->dio->write(command[0]->dio->terminateClient);
            return;
        }

        if (UserSelect >= 0 and UserSelect <= 4) {
            command[UserSelect]->execute();
            continue;
//        } else if (UserSelect == 4) { // Use thread
//            std::thread t([&](){ command[UserSelect]->execute(); });
//            std::unique_lock<std::mutex> lock(mtx);
//            t.join();
//            mtx.unlock();
//            continue;
        } else {    // Digit is 5-7, 9 or 0
            command[0]->dio->write("Invalid input!\nTry again:");
            command[0]->dio->read();
        }
    }
}


/**
 * Constructor for the class.
 * @param data - Basic data class.
 * @param defaultIo1 - A *defaultIo to send and receive input.
 */
CLI::CLI(Data *data, DefaultIO *defaultIo1) {
    this->data = data;
    this->defaultIo = defaultIo1;
//    data->unclassifiedFile="4.6,3.1,1.5,0.2\r6.9,3.1,4.9,1.5\r6.3,3.3,6,2.5\r6.5,2.8,4.6,1.5\r6.4,3.2,4.5,1.5\r4.7,3.2,1.3,0.2\r5.8,2.7,5.1,1.9\r5.1,3.5,1.4,0.2\r6.3,2.9,5.6,1.8\r5,3.6,1.4,0.2\r5.5,2.3,4,1.3\r7.1,3,5.9,2.1\r6.5,3,5.8,2.2\r7,3.2,4.7,1.4\r4.9,3,1.4,0.2\r6.8,3.2,5.9,2.3done"
//    ;
//    data->classifiedFile="5.4,3.9,1.7,0.4,Iris-setosa\\r4.6,3.4,1.4,0.3,Iris-setosa\\r5.0,3.4,1.5,0.2,Iris-setosa\\r4.4,2.9,1.4,0.2,Iris-setosa\\r4.9,3.1,1.5,0.1,Iris-setosa\\r5.4,3.7,1.5,0.2,Iris-setosa\\r4.8,3.4,1.6,0.2,Iris-setosa\\r4.8,3.0,1.4,0.1,Iris-setosa\\r4.3,3.0,1.1,0.1,Iris-setosa\\r5.8,4.0,1.2,0.2,Iris-setosa\\r5.7,4.4,1.5,0.4,Iris-setosa\\r5.4,3.9,1.3,0.4,Iris-setosa\\r5.1,3.5,1.4,0.3,Iris-setosa\\r5.7,3.8,1.7,0.3,Iris-setosa\\r5.1,3.8,1.5,0.3,Iris-setosa\\r5.4,3.4,1.7,0.2,Iris-setosa\\r5.1,3.7,1.5,0.4,Iris-setosa\\r4.6,3.6,1.0,0.2,Iris-setosa\\r5.1,3.3,1.7,0.5,Iris-setosa\\r4.8,3.4,1.9,0.2,Iris-setosa\\r5.0,3.0,1.6,0.2,Iris-setosa\\r5.0,3.4,1.6,0.4,Iris-setosa\\r5.2,3.5,1.5,0.2,Iris-setosa\\r5.2,3.4,1.4,0.2,Iris-setosa\\r4.7,3.2,1.6,0.2,Iris-setosa\\r4.8,3.1,1.6,0.2,Iris-setosa\\r5.4,3.4,1.5,0.4,Iris-setosa\\r5.2,4.1,1.5,0.1,Iris-setosa\\r5.5,4.2,1.4,0.2,Iris-setosa\\r4.9,3.1,1.5,0.1,Iris-setosa\\r5.0,3.2,1.2,0.2,Iris-setosa\\r5.5,3.5,1.3,0.2,Iris-setosa\\r4.9,3.1,1.5,0.1,Iris-setosa\\r4.4,3.0,1.3,0.2,Iris-setosa\\r5.1,3.4,1.5,0.2,Iris-setosa\\r5.0,3.5,1.3,0.3,Iris-setosa\\r4.5,2.3,1.3,0.3,Iris-setosa\\r4.4,3.2,1.3,0.2,Iris-setosa\\r5.0,3.5,1.6,0.6,Iris-setosa\\r5.1,3.8,1.9,0.4,Iris-setosa\\r4.8,3.0,1.4,0.3,Iris-setosa\\r5.1,3.8,1.6,0.2,Iris-setosa\\r4.6,3.2,1.4,0.2,Iris-setosa\\r5.3,3.7,1.5,0.2,Iris-setosa\\r5.0,3.3,1.4,0.2,Iris-setosa\\r5.7,2.8,4.5,1.3,Iris-versicolor\\r6.3,3.3,4.7,1.6,Iris-versicolor\\r4.9,2.4,3.3,1.0,Iris-versicolor\\r6.6,2.9,4.6,1.3,Iris-versicolor\\r5.2,2.7,3.9,1.4,Iris-versicolor\\r5.0,2.0,3.5,1.0,Iris-versicolor\\r5.9,3.0,4.2,1.5,Iris-versicolor\\r6.0,2.2,4.0,1.0,Iris-versicolor\\r6.1,2.9,4.7,1.4,Iris-versicolor\\r5.6,2.9,3.6,1.3,Iris-versicolor\\r6.7,3.1,4.4,1.4,Iris-versicolor\\r5.6,3.0,4.5,1.5,Iris-versicolor\\r5.8,2.7,4.1,1.0,Iris-versicolor\\r6.2,2.2,4.5,1.5,Iris-versicolor\\r5.6,2.5,3.9,1.1,Iris-versicolor\\r5.9,3.2,4.8,1.8,Iris-versicolor\\r6.1,2.8,4.0,1.3,Iris-versicolor\\r6.3,2.5,4.9,1.5,Iris-versicolor\\r6.1,2.8,4.7,1.2,Iris-versicolor\\r6.4,2.9,4.3,1.3,Iris-versicolor\\r6.6,3.0,4.4,1.4,Iris-versicolor\\r6.8,2.8,4.8,1.4,Iris-versicolor\\r6.7,3.0,5.0,1.7,Iris-versicolor\\r6.0,2.9,4.5,1.5,Iris-versicolor\\r5.7,2.6,3.5,1.0,Iris-versicolor\\r5.5,2.4,3.8,1.1,Iris-versicolor\\r5.5,2.4,3.7,1.0,Iris-versicolor\\r5.8,2.7,3.9,1.2,Iris-versicolor\\r6.0,2.7,5.1,1.6,Iris-versicolor\\r5.4,3.0,4.5,1.5,Iris-versicolor\\r6.0,3.4,4.5,1.6,Iris-versicolor\\r6.7,3.1,4.7,1.5,Iris-versicolor\\r6.3,2.3,4.4,1.3,Iris-versicolor\\r5.6,3.0,4.1,1.3,Iris-versicolor\\r5.5,2.5,4.0,1.3,Iris-versicolor\\r5.5,2.6,4.4,1.2,Iris-versicolor\\r6.1,3.0,4.6,1.4,Iris-versicolor\\r5.8,2.6,4.0,1.2,Iris-versicolor\\r5.0,2.3,3.3,1.0,Iris-versicolor\\r5.6,2.7,4.2,1.3,Iris-versicolor\\r5.7,3.0,4.2,1.2,Iris-versicolor\\r5.7,2.9,4.2,1.3,Iris-versicolor\\r6.2,2.9,4.3,1.3,Iris-versicolor\\r5.1,2.5,3.0,1.1,Iris-versicolor\\r5.7,2.8,4.1,1.3,Iris-versicolor\\r7.6,3.0,6.6,2.1,Iris-virginica\\r4.9,2.5,4.5,1.7,Iris-virginica\\r7.3,2.9,6.3,1.8,Iris-virginica\\r6.7,2.5,5.8,1.8,Iris-virginica\\r7.2,3.6,6.1,2.5,Iris-virginica\\r6.5,3.2,5.1,2.0,Iris-virginica\\r6.4,2.7,5.3,1.9,Iris-virginica\\r6.8,3.0,5.5,2.1,Iris-virginica\\r5.7,2.5,5.0,2.0,Iris-virginica\\r5.8,2.8,5.1,2.4,Iris-virginica\\r6.4,3.2,5.3,2.3,Iris-virginica\\r6.5,3.0,5.5,1.8,Iris-virginica\\r7.7,3.8,6.7,2.2,Iris-virginica\\r7.7,2.6,6.9,2.3,Iris-virginica\\r6.0,2.2,5.0,1.5,Iris-virginica\\r6.9,3.2,5.7,2.3,Iris-virginica\\r5.6,2.8,4.9,2.0,Iris-virginica\\r7.7,2.8,6.7,2.0,Iris-virginica\\r6.3,2.7,4.9,1.8,Iris-virginica\\r6.7,3.3,5.7,2.1,Iris-virginica\\r7.2,3.2,6.0,1.8,Iris-virginica\\r6.2,2.8,4.8,1.8,Iris-virginica\\r6.1,3.0,4.9,1.8,Iris-virginica\\r6.4,2.8,5.6,2.1,Iris-virginica\\r7.2,3.0,5.8,1.6,Iris-virginica\\r7.4,2.8,6.1,1.9,Iris-virginica\\r7.9,3.8,6.4,2.0,Iris-virginica\\r6.4,2.8,5.6,2.2,Iris-virginica\\r6.3,2.8,5.1,1.5,Iris-virginica\\r6.1,2.6,5.6,1.4,Iris-virginica\\r7.7,3.0,6.1,2.3,Iris-virginica\\r6.3,3.4,5.6,2.4,Iris-virginica\\r6.4,3.1,5.5,1.8,Iris-virginica\\r6.0,3.0,4.8,1.8,Iris-virginica\\r6.9,3.1,5.4,2.1,Iris-virginica\\r6.7,3.1,5.6,2.4,Iris-virginica\\r6.9,3.1,5.1,2.3,Iris-virginica\\r5.8,2.7,5.1,1.9,Iris-virginica\\r6.8,3.2,5.9,2.3,Iris-virginica\\r6.7,3.3,5.7,2.5,Iris-virginica\\r6.7,3.0,5.2,2.3,Iris-virginica\\r6.3,2.5,5.0,1.9,Iris-virginica\\r6.5,3.0,5.2,2.0,Iris-virginica\\r6.2,3.4,5.4,2.3,Iris-virginica\\r5.9,3.0,5.1,1.8,Iris-virginicadone"
//;
    this->command[0] = new Upload(data, defaultIo1);
    this->command[1] = new AlgoSettings(data, defaultIo1);
    this->command[2] = new ClassifyData(data, defaultIo1);
    this->command[3] = new DisplayResults(data, defaultIo1);
    this->command[4] = new DownloadResults(data, defaultIo1);
}