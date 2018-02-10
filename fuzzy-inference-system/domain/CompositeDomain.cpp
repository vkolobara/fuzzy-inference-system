//
// Created by vkolobara on 16.12.2017..
//

#include "CompositeDomain.h"

Domain* CompositeDomain::getComponent(uint index) {
    if (index < 0 || index > getNumberOfComponents()) {
        throw invalid_argument("Index greater than number of components");
    }
    return domains.at(index);
}

uint CompositeDomain::getNumberOfComponents() {
    return static_cast<uint>(domains.size());
}

uint CompositeDomain::getCardinality() {
    uint cardinality = 1;

    for (const auto &domain : domains) {
        cardinality *= domain->getCardinality();
    }

    return cardinality;
}

CompositeDomain::CompositeDomain(initializer_list<RangeDomain*> domains) {
    this->domains = std::vector<RangeDomain*>(domains);
}