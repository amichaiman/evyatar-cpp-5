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
    if (!goodFileState(file)) {
        throw InvalidTypeException();
    }
    targetGroup.init(file, groupSize, initialGroupDimension, targetGroupDimension);
    file.close();
}


bool Simulation::goodFileState(const std::ifstream &file) {
    return !file.fail() && !file.bad();
}
