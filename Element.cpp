#include <cstdlib>
#include <cmath>
#include <iostream>
#include "Element.h"

Element::Element(int initialGroupDimension, int targetGroupDimension)
: initialGroupDimension(initialGroupDimension),
  targetGroupDimension(targetGroupDimension),
  initialGroup(new double[initialGroupDimension]),
  targetGroup(new double[targetGroupDimension]()) {}

double sixDecimalPoints(double n) {
    return floor(n*1000000)/1000000;

}

ostream& operator<<(ostream &cout, Element element){
    for (int i=0; i<element.targetGroupDimension; i++) {
        cout << sixDecimalPoints(element.targetGroup[i]);
        if (i != element.targetGroupDimension-1) {
            cout << ' ';
        }
    }
    return cout;
}

double square(double n) {
    return n*n;
}

void Element::createTargetGroup() {
    for (int i=0; i<targetGroupDimension; i++) {
        for (int j=0; j<initialGroupDimension; j++) {
            targetGroup[i] += square(initialGroup[j]-(i+1));
        }
    }
}

Element *Element::clone() {
    Element *copy = new Element(initialGroupDimension, targetGroupDimension);
    for (int i=0; i<targetGroupDimension; i++) {
        copy->targetGroup[i] = targetGroup[i];
    }
    return copy;
}

double randomZeroOne() {
    return static_cast<double>(rand())/RAND_MAX;

}

void Element::moveByRandom() {
    for (int i=0; i<targetGroupDimension; i++) {
        targetGroup[i] += randomZeroOne();
    }
}

bool Element::operator>(Element &element) const {
    return isDominant(element);
}

bool Element::isDominant(Element &element) const {
    bool oneIsSmaller = false;
    for (int i=0; i<targetGroupDimension; i++) {
        if (targetGroup[i] > element.targetGroup[i]) {
            return false;
        }
        if (targetGroup[i] < element.targetGroup[i]) {
            oneIsSmaller = true;
        }
    }
    return oneIsSmaller;
}

void Element::swap(Element &element) {
    double temp;
    for (int i=0; i<targetGroupDimension; i++) {
        temp = targetGroup[i];
        targetGroup[i] = element.targetGroup[i];
        element.targetGroup[i] = temp;
    }
}

