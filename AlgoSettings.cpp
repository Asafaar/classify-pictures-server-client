/**
 * Settings for the program:
 * Client can change the k or metric, or both.
 */

#include "InputFile.h"
#include "AlgoSettings.h"
#include <string>

/**
 * Make an array out of the input to make it easy to test.
 * @param arr - The array to add the params into.
 * @param clientInput - The input string.
 */
void AlgoSettings::stringToArray(std::string *arr[2], std::string clientInput) {
    int i = 0;
    char curr = '0';
    // Get first word
    while (curr != ' ' && i < clientInput.length()) {
        curr = clientInput.at(i);
        i++;

    }
    // Create the array
    auto *k = new string(clientInput.substr(0, i - 1));
    auto *func = new string(clientInput.substr(i));
    arr[0] = k;
    arr[1] = func;
}

/**
 * Check if k is valid.
 * @param strToK - The string to make sure is valid.
 * @return True if k is a positive num, false otherwise.
 */
bool AlgoSettings::IsAPositiveNumber(string *strToK) {
    InputFile inputFile;
    int i = 0;
    // Allow sign
    if (strToK->at(i) == '+') {
        i++;
    }
    // Make sure k is a number
    for (; i < strToK->length(); i++) {
        if (!isdigit(strToK->at(i))) {
            return false;
        }
    }
    // Convert and return k
    int k = stoi(*strToK);
    return inputFile.kNumIsValid(k);
}

/**
 * Check if the client input fits the params k and the metric.
 */
void AlgoSettings::execute() {
    // Send current settings
    this->dio->write(
            "The current KNN parameters are: k = " + this->data->Knum + ", distance mertic = " + this->data->dis);
    this->dio->read();
    this->dio->write(this->dio->sendAnswer);
    std::string stringInput = this->dio->read();
    // String is empty
    if (stringInput.empty()) {
        return;
    } else {
        InputFile inputFile;
        std::string *clientInput[2];
        stringToArray(clientInput, stringInput);
        // Check if k is a valid number
        bool kIsOk = IsAPositiveNumber(clientInput[0]);
        // Check if the metric is valid
        bool disIsOk = inputFile.distanceIsValid(*clientInput[1]);
        // K is not valid
        if (kIsOk)  {
            this->data->Knum = *clientInput[0];
        } else {
            this->dio->write("Invalid value for K");
            this->dio->read();
        }
        // The metric is not valid
        if (disIsOk) {
            this->data->dis = *clientInput[1];
        } else {
            this->dio->write("Invalid value for metric");
            this->dio->read();
        }
        if (kIsOk && disIsOk){
            this->data->Knum = *clientInput[0];
            this->data->dis = *clientInput[1];
        }
        return;
    }
}

/**
 * Constructor for the class.
 * @param data - Basic data class.
 * @param defaultIo1 - A *defaultIo to send and receive input.
 */
AlgoSettings::AlgoSettings(Data *data, DefaultIO *defaultIo1) {
    this->description = "algorithm settings";
    this->data = data;
    this->dio = defaultIo1;
}
