#include <iostream>
#include "TargetGroup.h"

inline double square(double n) {
    return n*n;
}
void TargetGroup::init(ifstream &file, int groupSize, int initialGroupDimension, int targetGroupDimension) {
    double currentInitialVector[initialGroupDimension];
    double currentTargetVector[targetGroupDimension];

    for (int i=0; i<groupSize; i++) {                       //iterate over rows
        for (int j=0; j <targetGroupDimension; j++) {
            currentTargetVector[j] = 0;
            for (int k=0; k<initialGroupDimension; k++) {  //iterate over columns
                if (j==0) {         //fill array from file in first iteration
                    file >> currentInitialVector[k];
                    /* if invalid file format */
                    if ((initialGroupDimension-1 == k && file.peek() != '\n') || (initialGroupDimension-1 != k && file.peek() != ' ')) {
                        throw InvalidDefinitionException(initialGroupDimension);
                    }
                }
                cout << currentInitialVector[k] << (k == initialGroupDimension-1 ? '\n' : ' ');
                currentTargetVector[j] += square(currentInitialVector[k]-(j+1));
            }
        }
        cout << "pushed!" << endl;
        elements.push_back(Element(currentTargetVector, targetGroupDimension));
    }
}
