//
// Created by vkolobara on 12/26/17.
//

#include "Domain.h"
#include "RangeDomain.h"

DomainElement Domain::getElementAt(uint index) {
    if (index > getCardinality()) {
        //TODO: ERROR
    }

    uint numComponents = getNumberOfComponents();
    double values[numComponents];

    int divisor = 1;

    for (uint i = numComponents - 1; i > 0; i--) {
        int card = getComponent(i)->getCardinality();
        values[i] = getComponent(i)->getElementAt(index / divisor % card).getComponentValue(0);
        divisor*=card;
    }

    std::vector<double> ret(begin(values), end(values));

    return DomainElement(ret);
}

int Domain::indexOfElement(DomainElement element) {
    if (element.getNumberOfComponents() != getNumberOfComponents()) {
        return -1;
    }

    int index=0;

    for (uint i=0; i<element.getNumberOfComponents(); i++) {
        double value = element.getComponentValue(i);
        shared_ptr<RangeDomain> domain = getComponent(i);

        if (value >= domain->getEnd()) {
            return -1;
        }

        int ind = static_cast<int>((element.getComponentValue(i) - domain->getStart()) / domain->getStep());

        if (ind < 0) return -1;



        if (i == element.getNumberOfComponents()-1) {
            index+=ind;
        } else {
            index += ind*getComponent(i+1)->getCardinality();
        }


    }

    return index;
}
