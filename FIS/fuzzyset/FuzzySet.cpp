//
// Created by vkolobara on 12/26/17.
//

#include "FuzzySet.h"

shared_ptr<Domain> CalculatedFuzzySet::getDomain() {
    return domain;
}

double CalculatedFuzzySet::getValueAt(double el) {
    if (domain->indexOfElement(el) == -1) return 0;
    return function->valueAt(el);
}

CalculatedFuzzySet::CalculatedFuzzySet(shared_ptr<MembershipFunction> function, shared_ptr<Domain> domain)
        : function(function), domain(domain) {}

shared_ptr<Domain> MutableFuzzySet::getDomain() {
    return domain;
}

MutableFuzzySet::MutableFuzzySet(shared_ptr<Domain>domain) : domain(domain) {
    memberships = vector<double>(domain->getCardinality());
}

double MutableFuzzySet::getValueAt(double el) {
    int index = domain->indexOfElement(el);
    if (index == -1) {
        //TODO: ERROR
    }
    return memberships.at(index);
}

void MutableFuzzySet::set(double el, double mu) {

    int index = domain->indexOfElement(std::move(el));

    memberships.at(index) = mu;
}

shared_ptr<FuzzySet>
FuzzySet::combine(shared_ptr<FuzzySet> set1, shared_ptr<FuzzySet> set2, shared_ptr<BinaryFunction> f) {

    auto set = make_shared<MutableFuzzySet>(set1->getDomain());

    for (unsigned int i = 0; i < set->getDomain()->getCardinality(); i++) {
        double el = set->getDomain()->getElementAt(i);
        set->set(el, f->calculateValue(set1->getValueAt(el), set2->getValueAt(el)));
    }

    return set;
}

NegatedFuzzySet::NegatedFuzzySet(shared_ptr<FuzzySet> fuzzySet,
                                 shared_ptr<BaseOperator::Complement> complement) : fuzzySet(fuzzySet),
                                                                                           complement(complement) {}

shared_ptr<Domain> NegatedFuzzySet::getDomain() {
    return fuzzySet->getDomain();
}

double NegatedFuzzySet::getValueAt(double el) {
    return complement->calculateValue(fuzzySet->getValueAt(el));
}

ConcentratedFuzzySet::ConcentratedFuzzySet(shared_ptr<FuzzySet> fuzzySet) : fuzzySet(fuzzySet) {}

shared_ptr<Domain> ConcentratedFuzzySet::getDomain() {
    return fuzzySet->getDomain();
}

double ConcentratedFuzzySet::getValueAt(double el) {
    auto val = fuzzySet->getValueAt(el);
    return val*val;
}

DilatedFuzzySet::DilatedFuzzySet(shared_ptr<FuzzySet> fuzzySet) : fuzzySet(fuzzySet) {}

shared_ptr<Domain> DilatedFuzzySet::getDomain() {
    return fuzzySet->getDomain();
}

double DilatedFuzzySet::getValueAt(double el) {
    auto val = fuzzySet->getValueAt(el);
    return sqrt(val);
}