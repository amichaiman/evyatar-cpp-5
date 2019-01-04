//
// Created by amichai on 04/01/19.
//

#include "Element.h"

Element::Element(double *vector, int dimension) : values(new double[dimension]){
    Element::dimension = dimension;
    for (int i=0 ; i<dimension; i++)  {
        values[i] = vector[i];
    }
}

Element::~Element() {
    delete values;
}
