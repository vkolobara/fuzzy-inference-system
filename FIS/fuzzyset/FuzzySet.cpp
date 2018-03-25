//
// Created by vkolobara on 12/26/17.
//

#include "FuzzySet.h"

Domain* CalculatedFuzzySet::getDomain() {
    return domain;
}

double CalculatedFuzzySet::getValueAt(double el) {
    if (domain->indexOfElement(el) == -1) return 0;
    return function->valueAt(el);
}

CalculatedFuzzySet::CalculatedFuzzySet(MembershipFunction* function, Domain* domain)
        : function(function), domain(domain) {}

Domain* MutableFuzzySet::getDomain() {
    return domain;
}

MutableFuzzySet::MutableFuzzySet(Domain *domain) : domain(domain) {
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

FuzzySet *
FuzzySet::combine(FuzzySet* set1, FuzzySet* set2, BinaryFunction* f) {

    auto set = new MutableFuzzySet(set1->getDomain());

    for (unsigned int i = 0; i < set->getDomain()->getCardinality(); i++) {
        double el = set->getDomain()->getElementAt(i);
        set->set(el, f->calculateValue(set1->getValueAt(el), set2->getValueAt(el)));
    }

    return set;
}

NegatedFuzzySet::NegatedFuzzySet(FuzzySet* fuzzySet,
                                 BaseOperator::Complement* complement) : fuzzySet(fuzzySet),
                                                                                           complement(complement) {}

Domain* NegatedFuzzySet::getDomain() {
    return fuzzySet->getDomain();
}

double NegatedFuzzySet::getValueAt(double el) {
    return complement->calculateValue(fuzzySet->getValueAt(el));
}

ConcentratedFuzzySet::ConcentratedFuzzySet(FuzzySet* fuzzySet) : fuzzySet(fuzzySet) {}

Domain* ConcentratedFuzzySet::getDomain() {
    return fuzzySet->getDomain();
}

double ConcentratedFuzzySet::getValueAt(double el) {
    auto val = fuzzySet->getValueAt(el);
    return val*val;
}

DilatedFuzzySet::DilatedFuzzySet(FuzzySet* fuzzySet) : fuzzySet(fuzzySet) {}

Domain* DilatedFuzzySet::getDomain() {
    return fuzzySet->getDomain();
}

double DilatedFuzzySet::getValueAt(double el) {
    auto val = fuzzySet->getValueAt(el);
    return sqrt(val);
}