//
// Created by amichai on 04/01/19.
//

#ifndef EVYATAR_CPP_5_SIMULATION_H
#define EVYATAR_CPP_5_SIMULATION_H
#include <iostream>
#include <sstream>
#include <cstring>
#include "TargetGroup.h"

using namespace std;

class Simulation {
public:
    void init(char* filename);
    struct InvalidFileException : public exception {
        const char* filename;

        explicit InvalidFileException(const char* filename) : filename(filename){ }

        virtual const char *what() const throw(){
            stringstream ss;
            ss << "ERROR: " << filename << " does not exist or cannot be opened";
            char *message = new char[ss.str().length()+1];
            strcpy(message,ss.str().c_str());
            return message;
        }
    };
    struct InvlidDefinitionException : public exception {
        const char* filename;
        explicit InvlidDefinitionException(const char* filename) : filename(filename){ }
        virtual const char *what() const throw(){
            stringstream ss;
            ss << "ERROR: simulation definition in " << filename << " is invalid";
            char *message = new char[ss.str().length()+1];
            strcpy(message,ss.str().c_str());
            return message;
        }
    };

    void simulate(const char *outputfile);

private:
    int iterations;
    TargetGroup targetGroup;
};


#endif //EVYATAR_CPP_5_SIMULATION_H
