//
// Created by vkolobara on 16.12.2017..
//

#include "CompositeDomain.h"

Domain* CompositeDomain::getComponent(unsigned int index) {
    if (index < 0 || index > getNumberOfComponents()) {
        throw invalid_argument("Index greater than number of components");
    }
    return domains.at(index);
}

unsigned int CompositeDomain::getNumberOfComponents() {
    return static_cast<unsigned int>(domains.size());
}

unsigned int CompositeDomain::getCardinality() {
    unsigned int cardinality = 1;

    for (const auto &domain : domains) {
        cardinality *= domain->getCardinality();
    }

    return cardinality;
}

CompositeDomain::CompositeDomain(initializer_list<RangeDomain*> domains) {
    this->domains = std::vector<RangeDomain*>(domains);
}