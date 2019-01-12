#include "Simulation.h"
#include <fstream>

void Simulation::init(char* filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw InvalidFileException(filename);
    }
    int groupSize;
    int initialGroupDimension;
    int targetGroupDimension;

    file >> groupSize >> initialGroupDimension >> targetGroupDimension >> iterations;
    if (file.bad() || file.fail() || groupSize > TargetGroup::MAX_GROUP_SIZE || initialGroupDimension > Element::MAX_INITIAL_VECTOR_SIZE || targetGroupDimension >= initialGroupDimension) {
        throw InvlidDefinitionException(filename);
    }
    targetGroup.init(filename, file, groupSize, initialGroupDimension, targetGroupDimension);
    file.close();
}

void Simulation::simulate(const char *outputfile) {
    for (int i=0; i<iterations; i++) {
        targetGroup.update();
    }
    ofstream file(outputfile);
    if (!file.is_open()) {
        throw InvalidFileException(outputfile);
    }
    file << targetGroup;
}

