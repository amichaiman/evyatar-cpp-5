//
// Created by amichai on 04/01/19.
//

#ifndef EVYATAR_CPP_5_TARGETGROUP_H
#define EVYATAR_CPP_5_TARGETGROUP_H

#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
#include "Element.h"

using namespace std;

class TargetGroup {
public:
    void init(ifstream &file, int groupSize, int initialGroupDimension, int targetGroupDimension);
    struct InvalidDefinitionException : public exception {
        int value;

        explicit InvalidDefinitionException(int numberOfColumns) : value(numberOfColumns){ }

        virtual const char *what() const throw(){
            stringstream ss;
            ss << "ERROR: simulation definition in " << value << " is invalid";
            char *message = new char[ss.str().length()+1];
            strcpy(message,ss.str().c_str());
            return message;
        }
    };
private:
    vector<Element> elements;
};


#endif //EVYATAR_CPP_5_TARGETGROUP_H
