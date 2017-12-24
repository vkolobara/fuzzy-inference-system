//
// Created by vkolobara on 16.12.2017..
//

#include "CompositeDomain.h"
#include <stdexcept>

shared_ptr<Domain> CompositeDomain::getComponent(uint index) {
    if (index < 0 || index > getNumberOfComponents()) {
        throw invalid_argument("Index greater than number of components");
    }
    return domains[index];
}

uint CompositeDomain::getNumberOfComponents() {
    return domains.size();
}

uint CompositeDomain::getCardinality() {
    return 0;
}

DomainElement CompositeDomain::getElementAt(uint index) {
    return DomainElement(std::initializer_list<double>());
}

uint CompositeDomain::indexOfElement(DomainElement element) {
    return 0;
}
