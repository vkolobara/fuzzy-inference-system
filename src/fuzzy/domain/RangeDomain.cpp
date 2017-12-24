//
// Created by vkolobara on 16.12.2017..
//

#include "RangeDomain.h"

RangeDomain::RangeDomain(double start, double step, double end) : start(start), step(step), end(end) {}

DomainElement RangeDomain::getElementAt(uint index) {
    if (index > getCardinality()) {
        throw std::invalid_argument("Index greater than size of domain");
    }
    return DomainElement({start + index * step});
}

uint RangeDomain::getCardinality() {
    return static_cast<uint>((end - start) / step);
}

shared_ptr<Domain> RangeDomain::getComponent(uint index) {
    return shared_from_this();
}

uint RangeDomain::indexOfElement(DomainElement element) {

    return 0;
}

unsigned long RangeDomain::getNumberOfComponents() {
    return 1;
}
