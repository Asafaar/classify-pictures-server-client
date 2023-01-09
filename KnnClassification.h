//
// Created by micro on 03/12/2022.
//

#ifndef ASS2_KNNCLASSIFICATION_H
#define ASS2_KNNCLASSIFICATION_H

#include "InputFile.h"
#include "string"
#include <vector>
#include <list>
using namespace std;

struct classificationItem {
    string name;
    int numOfAppereances = 0;
};
void calculateDistance(vector<VectorData*> *classifiedVec, const vector<long double>& unclassifiedVec, const string& distanceFunc);
int compare(VectorData *data1, VectorData *data2);
void swap(VectorData *data1, VectorData *data2);
void sort(vector<VectorData*> *classifiedVec);
void countClassificationsByK(list<classificationItem *> *classifyByKList, vector<VectorData*> *classifiedVec, int k);
string* knn(vector<VectorData*> *classifiedVec, const vector<long double>& unclassifiedVec, const string& distanceFunc, int k);

#endif //ASS2_KNNCLASSIFICATION_H
