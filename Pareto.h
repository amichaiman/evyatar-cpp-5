#ifndef EVYATAR_CPP_5_PARETO_H
#define EVYATAR_CPP_5_PARETO_H

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
class Pareto {
public:
    static void ParetoSorting(T &elements);
    static void ParetoRanking(T &elements, int *ranks);
    static void Rank(T &vector, unsigned int toRank, int* ranks);
    static void ElementsReordering(T &vector, int *ranks);
};

template <typename T>
void Pareto<T>::ParetoSorting(T &elements) {
    int *ranks = new int[elements.size()]();
    ParetoRanking(elements, ranks);
    ElementsReordering(elements, ranks);
}

template <typename T>
void Pareto<T>::ParetoRanking(T &elements, int* ranks) {
    for (unsigned int i=0; i<elements.size(); i++) {
        Rank(elements, i, ranks);
    }
}

template <typename T>
void Pareto<T>::Rank(T &vector, unsigned int toRank, int* ranks) {
    for (unsigned int i=0; i<vector.size(); i++) {
        if (i != toRank) {
            if (*(vector[i]) > *(vector[toRank])) {
                ranks[toRank]++;
            }
        }
    }
}

template <typename T>
void Pareto<T>::ElementsReordering(T &vector, int *ranks) {
    for (unsigned int i=vector.size(); i>1; i--) {
        for (unsigned int j=0; j<i-1; j++) {
            if (ranks[j] > ranks[j+1]) {
                int temp = ranks[j];
                ranks[j] = ranks[j+1];
                ranks[j+1] = temp;
                vector[j]->swap(*(vector[j+1]));
            }
        }
    }
}

#endif //EVYATAR_CPP_5_PARETO_H
