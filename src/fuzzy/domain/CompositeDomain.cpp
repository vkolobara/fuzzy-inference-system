//
// Created by vkolobara on 16.12.2017..
//

#include "CompositeDomain.h"
#include <stdexcept>

shared_ptr<Domain> CompositeDomain::getComponent(int index) {
    if (index < 0 || index > getNumberOfComponents()) {
        throw invalid_argument("Index greater than number of components");
    }
    return domains[index];
}

int CompositeDomain::getNumberOfComponents() {
    return domains.size();
}
