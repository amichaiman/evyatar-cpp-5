//
// Created by amichai on 04/01/19.
//

#ifndef EVYATAR_CPP_5_ELEMENT_H
#define EVYATAR_CPP_5_ELEMENT_H

#include <fstream>
using namespace std;

class Element {
public:
    Element(int initialGroupDimension, int targetGroupDimension);
    friend ifstream& operator>>(ifstream &stream, Element element);
    friend ostream& operator<<(ostream &os, Element element);
    static const int MAX_INITIAL_VECTOR_SIZE = 100;
    Element* clone();
    void createTargetGroup();
    bool operator>(Element &element) const;

    void moveByRandom();
    void swap(Element &element);
private:
    int initialGroupDimension;
    int targetGroupDimension;
    double *initialGroup;
    double *targetGroup;

    bool isDominant(Element &element) const;
};


#endif //EVYATAR_CPP_5_ELEMENT_H
