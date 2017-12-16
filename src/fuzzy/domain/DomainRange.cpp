//
// Created by vkolobara on 16.12.2017..
//

#include "DomainRange.h"

DomainRange::DomainRange(double start, double step, double end) : start(start), step(step), end(end) {}

DomainElement DomainRange::getElementAt(int index) {
    if (index > getCardinality()) {
        throw std::invalid_argument("Index greater than size of domain");
    }
    return DomainElement({start + index * step});
}

int DomainRange::getCardinality() {
    return (end - start) / step;
}

shared_ptr<Domain> DomainRange::getComponent(int index) {
    return shared_from_this();
}

int DomainRange::indexOfElement(DomainElement element) {

    return 0;
}

int DomainRange::getNumberOfComponents() {
    return 1;
}
