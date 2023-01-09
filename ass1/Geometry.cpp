/*
 * Class Geometry:
 * Includes a number of different ways calculate the distance of vectors,
 * and functions to receive input from the user and translate it into a vector.
 */

#include "Geometry.h"
#include <iostream>
#include "vector"
#include <cmath>
#include <cstdlib>
#include "string"
#include <stdlib.h>

using namespace std;

/*
 * Check if 2 vectors are of the same length.
 *
 * @param v1 - The 1st vector.
 * @param v2 - The 2nd vector.
 * @return true if the vectors are of the same length, false otherwise.
 */
void vectorsAreOfSameLength(vector<long double> v1, vector<long double> v2) {
    if (v1.size() != v2.size()) {
        cout << "Vectors not of the same size!" << endl;
        exit(0);
    }
}
/*
 * Check if 2 vectors are of the same length.
 *
 * @param v1 - The 1st vector.
 * @param v2 - The 2nd vector.
 * @return true if the vectors are of the same length, false otherwise.
 */
bool Geometry::vectorsAreOfSameLengthbool(vector<long double> v1, vector<long double> v2) {
    if (v1.size() != v2.size()) {
        cout << "Vectors not of the same size!" << endl;
        return false;}
     else return true;
}

/*
 * Calculate the Minkowski distance of 2 vectors.
 *
 * @param v1 - The 1st vector.
 * @param v2 - The 2nd vector.
 * @return the Minkowski distance.
 */
long double Geometry::MinkowskiDistance(vector<long double> v1, vector<long double> v2, long double Order_p) {
    // Make sure that the vectors are of the same length
    vectorsAreOfSameLength(v1, v2);

    int size_vector = v1.size();
    long double sum = 0;

    for (int i = 0; i < size_vector; i++) {
        // Sums up the absolute distance of each x to the power of given p
        long double temp = pow(std::abs(v1[i] - v2[i]), Order_p);
        sum += temp;
    }

    long double sq_p = 1 / Order_p;
    return pow(sum, sq_p);

}

/*
 * Calculate the Euclidean distance of 2 vectors.
 *
 * @param v1 - The 1st vector.
 * @param v2 - The 2nd vector.
 * @return the Euclidean distance.
 */
long double Geometry::EuclideanDistance(vector<long double> v1, vector<long double> v2) {
    // Make sure that the vectors are of the same length
    vectorsAreOfSameLength(v1, v2);
    // The same as Minkowski distance for our purpose.
    return MinkowskiDistance(v1, v2);
}

/*
 * Calculate the Euclidean distance of 2 vectors.
 *
 * @param v1 - The 1st vector.
 * @param v2 - The 2nd vector.
 * @return the Manhattan distance.
 */
long double Geometry::ManhattanDistance(vector<long double> v1, vector<long double> v2) {
    // Make sure that the vectors are of the same length
    vectorsAreOfSameLength(v1, v2);

    int size_vector = v1.size();
    long double sum = 0;

    for (int i = 0; i < size_vector; ++i) {
        // Sum up the distance of every point in the vector in absolute value
        long double temp = abs(v1[i] - v2[i]);
        sum += temp;
    }
    return sum;
}

/*
 * Find the max between a number and the distance of 2 other numbers.
 *
 * @param previousMax - The max to be checked with.
 * @param x - 1st point.
 * @param x2 - 2nd point.
 * @return the max between previousMax and (x-x2) in absolute value.
 */
long double Geometry::maxV(long double previousMax, long double x, long double x2) {
    // The maximum between previousMax and the distance between x and x2
    long double m = std::max(previousMax, abs(x - x2));
    return m;
}

//change format,print 4 and not 4.}

/*
 * Calculate the Chebyshev distance of 2 vectors.
 *
 * @param v1 - The 1st vector.
 * @param v2 - The 2nd vector.
 * @return the Chebyshev distance.
 */
long double Geometry::ChebyshevDistance(vector<long double> v1, vector<long double> v2) {
    // Make sure that the vectors are of the same length
    vectorsAreOfSameLength(v1, v2);

    long double max = 0;
    int size_vector = v1.size();

    for (int i = 0; i < size_vector; ++i) {
        // Checks the maximum distance
        max = maxV(max, v1[i], v2[i]);
    }
    return max;
}

/*
 * Calculate the Canberra distance of 2 vectors.
 *
 * @param v1 - The 1st vector.
 * @param v2 - The 2nd vector.
 * @return the Canberra distance.
 */
long double Geometry::CanberraDistance(vector<long double> v1, vector<long double> v2) {
    // Make sure that the vectors are of the same length
    vectorsAreOfSameLength(v1, v2);

    long double sum = 0;
    int size_vector = v1.size();

    for (int i = 0; i < size_vector; ++i) {
        // temp = the nominator
        long double temp = abs(v1[i] - v2[i]);
        // temp2 = the denominator
        long double temp2 = abs(v1[i]) + abs(v2[i]);
        // Can't divide by 0

        sum += temp / temp2;
    }
    return sum;
}

/*
 * Split a string into an array of numbers.
 *
 * @param *arr[] - The address of the array to save the numbers in.
 * @param input - The string to break into numbers.
 */
int Geometry::splitString(string *arr[], string input) {
    int i = 0, j = 0;
    // Run through the string
    while (i < input.length()) {
        // Start of a new number
        string temp = "";
        // Break when reaching the end of the string or a new number
        while (input[i] != ' ' && i < input.length()) {
            temp.push_back(input[i]);
            i++;
        }
        i++;
        if (temp != "") {
            // Enter the number into the array
            (*arr)[j] = temp;
            j++;
        }
    }
    return j;
}

/*
 * A function to check if a string is a real number.
 *
 * @param s - The string to check.
 * @return true if it's a real number, false otherwise.
 */
bool Geometry::stringIsANumber(string s) {
    int iterator = 0;
    bool hasPeriod = false;
    // Check sign and period at the beginning of the string
    if (s.at(0) == '.') {
        if (s.length() == 1 || s.at(1) == ' ') {
            return false;
        }
        iterator += 1;
        hasPeriod = true;
    } else if (s.at(0) == '-' || s.at(0) == '+') {
        iterator = 1;
    }

    // Run through the rest of the string and make sure it's a real number
    for (iterator; iterator < s.length(); iterator++) {
        // Make sure that there aren't 2 periods in the string
        if (s.at(iterator) == '.' && !hasPeriod) {
            hasPeriod = true;
            // char isn't a digit or first appearance of a period.
        } else if (!isdigit(s.at(iterator))) {
            return false;
        }
    }
    // String is a number
    return true;
}


/*
 * Break a string into numbers and enter them into a vector.
 * If an input is not a number, the function will ignore and skip it.
 *
 * @param string - The string to translate into a vector.
 * @return the vector comprised of the numbers in the string.
 */
vector<long double> Geometry::inputToVector(string input) {
    // An array to save the numbers from the string.
    string *inputArray = new string[input.length()];
    // Split the string into numbers and enter them into the array
    int size = splitString(&inputArray, input);
    vector<long double> vec;
    // Enter the numbers into the vector
    for (int i = 0; i < size; i++) {
        // Enter it into the vector only if it's a number
        // Enter it into the vector only if it's a number
        if (stringIsANumber(*(inputArray + i))) {
            long double temp = std::stof(*(inputArray + i));
            vec.push_back(temp);
        } else {
            cout << "The input contains strings that do not represent a number!" << endl;
            vec={0};
            return vec;// the fucntion change in ass2
        }
    }
    return vec;
}

/*
 * Get an input from the user and create a vector out of it.
 */
vector<long double> Geometry::getVector() {
    string input;
    //Get input from the user
    getline(cin, input);
    // Create and return the vector
    return inputToVector(input);
}

/*
 * Print the values in a vector.
 *
 * @param vec - The vector.
 */
void Geometry::printVector(vector<long double> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

/*
 * Print a double with a specified precision.
 *
 * @param x - The double to print.
 */
void Geometry::printDistance(long double x) {
    // If x is an int
    if (x - (int) x == 0) {
        cout.precision(1);
    } else {
        cout.precision(16);
    }
    cout << std::fixed;
    cout << x << endl;
}
