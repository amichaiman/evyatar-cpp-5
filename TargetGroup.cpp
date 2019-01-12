#include <iostream>
#include "TargetGroup.h"
#include "Pareto.h"

inline double square(double n) {
    return n*n;
}

ifstream& operator>>(ifstream &file, Element element){
    for (int i=0; i<element.initialGroupDimension; i++) {
        file >> element.initialGroup[i];
        if (file.bad() || file.fail() || file.peek() != (i == element.initialGroupDimension-1 ? '\n' : ' ')) {
            throw exception();
        }
    }
    return file;
}

void TargetGroup::init(const char *filename, ifstream &file, int groupSize, int initialGroupDimension, int targetGroupDimension) {
    TargetGroup::groupSize = groupSize;
    for (int i=0; i<groupSize; i++) {
        Element *element = new Element(initialGroupDimension, targetGroupDimension);
        try {
            file >> *element;
        } catch (exception &e) {
            throw InvalidPopulationDefinition(filename, i+2);
        }
        element->createTargetGroup();
        elements.push_back(element);
    }
}

void TargetGroup::update() {
    for (int i=0; i<groupSize; i++) {
        Element* movedByRandom = elements[i]->clone();
        movedByRandom->moveByRandom();
        elements.push_back(movedByRandom);
    }
    Pareto<vector<Element*> >::ParetoSorting(elements);
    for (int i=groupSize; i<2*groupSize; i++) {
        elements.erase(elements.begin()+groupSize);
    }
}

ostream &operator<<(ostream &out, TargetGroup targetGroup) {
    for (int i=0; i<targetGroup.groupSize; i++) {
        out << *(targetGroup.elements[i]) << endl;
    }
    return out;
}
