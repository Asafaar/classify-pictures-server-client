/**
 * The class in charge of running the program.
 */

#include "CLI.h"
#include "Upload.h"
#include "AlgoSettings.h"
#include "ClassifyData.h"
#include "DisplayResults.h"
#include "DownloadResults.h"

/**
 * Start running the program.
 */
void CLI::start() {
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
        }

        if (UserSelect >= 0 and UserSelect <= 4) {
            command[UserSelect]->execute();
            return;
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
    this->command[0] = new Upload(data, defaultIo1);
    this->command[1] = new AlgoSettings(data, defaultIo1);
    this->command[2] = new ClassifyData(data, defaultIo1);
    this->command[3] = new DisplayResults(data, defaultIo1);
    this->command[4] = new DownloadResults(data, defaultIo1);
}