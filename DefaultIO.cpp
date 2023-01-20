/**
 * A class with functions read or write - to be implemented by the inheriting classes.
 */
#include "DefaultIO.h"
#include <iostream>
using namespace std;

/**
 * Read input from terminal.
 * @return The client input.
 */
std::string DefaultIO::read() {
    std::string s;
    std::cin >> s;
    return s;
}

/**
 * Output to terminal.
 * @param string  - The string to output.
 */
void DefaultIO::write(std::string string) {
}


