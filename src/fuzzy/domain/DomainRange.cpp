//
// Created by vkolobara on 16.12.2017..
//

#include "DomainRange.h"

DomainRange::DomainRange(double start, double step, double end) : start(start), step(step), end(end) {}

DomainElement DomainRange::getElementAt(uint index) {
    if (index > getCardinality()) {
        throw std::invalid_argument("Index greater than size of domain");
    }
    return DomainElement({start + index * step});
}

uint DomainRange::getCardinality() {
    return static_cast<int>((end - start) / step);
}

shared_ptr<Domain> DomainRange::getComponent(uint index) {
    return shared_from_this();
}

uint DomainRange::indexOfElement(DomainElement element) {

    return 0;
}

uint DomainRange::getNumberOfComponents() {
    return 1;
}
