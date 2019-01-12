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
    static const int MAX_GROUP_SIZE = 1000;
    void init(const char *filename,ifstream &file, int groupSize, int initialGroupDimension, int targetGroupDimension);

    struct InvalidPopulationDefinition : public exception {
        const char* filename;
        const int line;

        explicit InvalidPopulationDefinition(const char* filename, int line) : filename(filename), line(line){ }
        virtual const char *what() const throw(){
            stringstream ss;
            ss << "ERROR: population definition in " << filename << " at line " << line << " is invalid";
            char *message = new char[ss.str().length()+1];
            strcpy(message,ss.str().c_str());
            return message;
        }
    };

    void update();
    friend ostream& operator<<(ostream& out, TargetGroup targetGroup);

private:
    vector<Element*> elements;
    int groupSize;
};


#endif //EVYATAR_CPP_5_TARGETGROUP_H
