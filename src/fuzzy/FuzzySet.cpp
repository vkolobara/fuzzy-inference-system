//
// Created by vkolobara on 12/26/17.
//

#include "FuzzySet.h"

shared_ptr<Domain> CalculatedFuzzySet::getDomain() {
    return domain;
}

double CalculatedFuzzySet::getValueAt(DomainElement el) {
    if (domain->indexOfElement(el) == -1) return 0;
    return function->valueAt(el.getComponentValue(0));
}

CalculatedFuzzySet::CalculatedFuzzySet(const shared_ptr<MembershipFunction> &function, const shared_ptr<Domain> &domain)
        : function(function), domain(domain) {}

shared_ptr<Domain> MutableFuzzySet::getDomain() {
    return domain;
}

MutableFuzzySet::MutableFuzzySet(const shared_ptr<Domain> &domain) : domain(domain) {
    memberships = vector<double>(domain->getCardinality());
}

double MutableFuzzySet::getValueAt(DomainElement el) {
    int index = domain->indexOfElement(el);
    if (index == -1) {
        //TODO: ERROR
    }
    return memberships.at(index);
}
