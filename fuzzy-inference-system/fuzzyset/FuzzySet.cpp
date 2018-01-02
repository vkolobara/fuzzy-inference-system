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

void MutableFuzzySet::set(DomainElement el, double mu) {

    int index = domain->indexOfElement(std::move(el));

    memberships.at(index) = mu;
}

shared_ptr<FuzzySet>
FuzzySet::combine(shared_ptr<FuzzySet> set1, shared_ptr<FuzzySet> set2, shared_ptr<BinaryFunction> f) {

    shared_ptr<MutableFuzzySet> set = make_shared<MutableFuzzySet>(set1->getDomain());

    for (uint i = 0; i < set->getDomain()->getCardinality(); i++) {
        DomainElement el = set->getDomain()->getElementAt(i);
        set->set(el, f->calculateValue(set1->getValueAt(el), set2->getValueAt(el)));
    }

    return set;
}

NegatedFuzzySet::NegatedFuzzySet(const shared_ptr<FuzzySet> &fuzzySet,
                                 const shared_ptr<BaseOperator::Complement> &complement) : fuzzySet(fuzzySet),
                                                                                           complement(complement) {}

shared_ptr<Domain> NegatedFuzzySet::getDomain() {
    return fuzzySet->getDomain();
}

double NegatedFuzzySet::getValueAt(DomainElement el) {
    return complement->calculateValue(fuzzySet->getValueAt(el));
}

ConcentratedFuzzySet::ConcentratedFuzzySet(const shared_ptr<FuzzySet> &fuzzySet) : fuzzySet(fuzzySet) {}

shared_ptr<Domain> ConcentratedFuzzySet::getDomain() {
    return fuzzySet->getDomain();
}

double ConcentratedFuzzySet::getValueAt(DomainElement el) {
    auto val = fuzzySet->getValueAt(el);
    return val*val;
}

DilatedFuzzySet::DilatedFuzzySet(const shared_ptr<FuzzySet> &fuzzySet) : fuzzySet(fuzzySet) {}

shared_ptr<Domain> DilatedFuzzySet::getDomain() {
    return fuzzySet->getDomain();
}

double DilatedFuzzySet::getValueAt(DomainElement el) {
    auto val = fuzzySet->getValueAt(el);
    return sqrt(val);
}