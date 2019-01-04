#include <iostream>
#include <cstdlib>
#include "TargetGroup.h"
#include "Simulation.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cerr << "USAGE: <executable> <init file name> <output file name>" << endl;
        exit(1);
    }
    Simulation simulation;
    try {
        simulation.init(argv[1]);
    } catch (const exception &e) {
        cout << e.what() << endl;
        exit(2);
    }
    return 0;
}