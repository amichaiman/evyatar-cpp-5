//
// Created by amichai on 04/01/19.
//

#ifndef EVYATAR_CPP_5_ELEMENT_H
#define EVYATAR_CPP_5_ELEMENT_H


class Element {
public:
    Element(double *vector, int dimension);

    virtual ~Element();

private:
    double *values;
    int dimension;
};


#endif //EVYATAR_CPP_5_ELEMENT_H
