//
// Created by micro on 16/11/2022.
//
//

#ifndef ASS1_PART2_GEOMETRY_H
#define ASS1_PART2_GEOMETRY_H

#include "iostream"
#include "vector"
#include "stdio.h"
using namespace std;

class Geometry {
public:
    long double MinkowskiDistance(vector<long double> v1, vector<long double> v2, long double Order_p=2);
    long double EuclideanDistance(vector<long double> v1, vector<long double> v2);
    long double ManhattanDistance(vector<long double> v1, vector<long double> v2);
    long double maxV(long double max, long double x, long double x2);
    long double ChebyshevDistance(vector<long double> v1, vector<long double> v2);
    long double CanberraDistance(vector<long double> v1, vector<long double> v2);
    int splitString(string *arr[], string input);
    vector<long double> inputToVector(string input);
    vector<long double> getVector();
    void printVector(vector<long double> vec);
    void printDistance(long double x);
    bool stringIsANumber(string s);
    bool vectorsAreOfSameLengthbool(vector<long double> v1, vector<long double> v2);
};


#endif //ASS1_PART2_GEOMETRY_H
