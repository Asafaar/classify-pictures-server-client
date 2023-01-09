#include <string>
#include <vector>
#include <list>
#include "KnnClassification.h"
#include "ass1/Geometry.h"

using namespace std;

/**
 * Calculate the distance between every vector in the classified file and the unclassified vector
 * according to a given distance function.
 *
 * @param data - A vector with all the classified vectors in the struct datacsv.
 * @param unclassifiedVec - The unclassified vector.
 * @param distanceFunc - A string representing a distance function to calculate with.
 */
void calculateDistance(vector<VectorData*> *classifiedVec, const vector<long double>& unclassifiedVec, const string& distanceFunc) {
    Geometry geometry;
    if (distanceFunc == "AUC") {
        for (VectorData* element: *classifiedVec) {
            element->Length = geometry.EuclideanDistance(element->vectorV, unclassifiedVec);
        }
    } else if (distanceFunc == "MAN") {
        for (VectorData* element: *classifiedVec) {
            element->Length = geometry.ManhattanDistance(element->vectorV, unclassifiedVec);
        }
    } else if (distanceFunc == "CHB") {
        for (VectorData* element: *classifiedVec) {
            element->Length = geometry.ChebyshevDistance(element->vectorV, unclassifiedVec);
        }
    } else if (distanceFunc == "CAN") {
        for (VectorData* element: *classifiedVec) {
            element->Length = geometry.CanberraDistance(element->vectorV, unclassifiedVec);
        }
    } else if (distanceFunc == "MIN") {
        for (VectorData* element: *classifiedVec) {
            element->Length = geometry.MinkowskiDistance(element->vectorV, unclassifiedVec);
        }
    }
}

/**
 * Compare between 2 datacsv objects.
 *
 * @param data1 - 1st object to compare.
 * @param data2 - 2nd object to compare.
 * @return 1 if 1st object's length param is bigger, -1 otherwise.
 */
int compare(VectorData* data1, VectorData* data2) {
    if (data1->Length < data2->Length) return 1;
    else return -1;
}

/**
 * swap 2 datacsv objects.
 *
 * @param data1 - 1st object to swap.
 * @param data2 - 2nd object to swap.
 */
void swap(VectorData *data1, VectorData *data2) {
    VectorData temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

/**
 * sort a datacsv vector according to its length parameter.
 *
 * @param classifiedVec - the vector to sort.
 */
void sort(vector<VectorData*> *classifiedVec) {
    for (int i = 0; i < classifiedVec->size(); i++) {
        for (int j = 0; j < classifiedVec->size(); j++) {
            if (compare(classifiedVec->at(i), classifiedVec->at(j)) > 0)
                swap(classifiedVec->at(i), classifiedVec->at(j));
        }
    }
}



/**
 * Creates a list of classification types and the num of times they appear in the first
 * k items of a vector.
 *
 * @param classifyByKList - the list to create.
 * @param classifiedVec - the vector with the items holding the classifications.
 * @param k - the num of items to classify by.
 */
void countClassificationsByK(list<classificationItem *> *classifyByKList, vector<VectorData*> *classifiedVec, int k) {
    // Create a first object inside the list with the details from the first object in the vector
    auto *item1 = new classificationItem();
    item1->numOfAppereances = 1;
    item1->name = classifiedVec->at(0)->name;
    classifyByKList->push_back(item1);
    // Loop through the first k objects in the vector and insert them to the list
    for (int i = 1; i < k; i++) {
        bool foundClassification = false;
        // The object is already in the list
        for (classificationItem *listItem: *classifyByKList) {
            if (listItem->name == classifiedVec->at(i)->name) {
                // Add 1 to existing object
                listItem->numOfAppereances += 1;
                foundClassification = true;
                break;
            }
        }
        // Not in the list yet - add it
        if (!foundClassification) {
            auto *newItem = new classificationItem();
            newItem->name = classifiedVec->at(i)->name;
            newItem->numOfAppereances = 1;
            classifyByKList->push_back(newItem);
        }
    }
}

/**
 * Check the classification of an unclassified vector according to other classified vectors by comparing it
 * to the closest k classified vectors.
 *
 * @param classifiedVec - A vector of classified vectors and their classifications.
 * @param unclassifiedVec - The unclassified vector.
 * @param distanceFunc - The function with which to calculate the distance of the vectors.
 * @param k - The k closest classified vectors with which to classify the unclassified vector.
 * @return the classification string in pointer
 */
string* knn(vector<VectorData*> *classifiedVec, const vector<long double>& unclassifiedVec, const string& distanceFunc, int k) {
    // Calculate the distance of all the classified vectors from the unclassified vector
    calculateDistance(classifiedVec, unclassifiedVec, distanceFunc);
    // Sort according to distance
    sort(classifiedVec);
    auto *classifyByKList =new list<classificationItem*>;
    // Check what the first k classifications are
    countClassificationsByK(classifyByKList, classifiedVec, k);

    string finalClassification;
    int maxAppearances = 0;
    // Check which classification is best suited to the unclassified vector according to the closest vectors
    // of the k classified ones.
    for (classificationItem *listItem: *classifyByKList) {
        if (listItem->numOfAppereances > maxAppearances) {
            finalClassification = listItem->name;
            maxAppearances = listItem->numOfAppereances;
        }
    }
    auto* finalClassificationPointer=new string;
    *finalClassificationPointer=finalClassification;
    return finalClassificationPointer;
}