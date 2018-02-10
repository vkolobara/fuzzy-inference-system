//
// Created by vkolobara on 12/26/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_FUZZYSET_H
#define FUZZY_INFERENCE_SYSTEM_FUZZYSET_H


#include "../domain/Domain.h"
#include "MembershipFunction.h"

class FuzzySet {

public:
    virtual Domain* getDomain() = 0;

    virtual double getValueAt(DomainElement el) = 0;

    static FuzzySet*
    combine(FuzzySet* set1, FuzzySet* set2, BinaryFunction* f);
};

class CalculatedFuzzySet : public FuzzySet {
private:
    MembershipFunction* function;
    Domain* domain;
public:
    CalculatedFuzzySet(MembershipFunction* function, Domain* domain);

    Domain* getDomain() override;

    double getValueAt(DomainElement el) override;
};

class MutableFuzzySet : public FuzzySet {
private:
    vector<double> memberships;
    Domain* domain;
public:
    explicit MutableFuzzySet(Domain* domain);

    Domain* getDomain() override;

    double getValueAt(DomainElement el) override;

    void set(DomainElement el, double mu);
};

class NegatedFuzzySet : public FuzzySet {
private:
    FuzzySet* fuzzySet;
    BaseOperator::Complement* complement;
public:
    NegatedFuzzySet(FuzzySet* fuzzySet, BaseOperator::Complement* complement);

    Domain* getDomain() override;

    double getValueAt(DomainElement el) override;
};

class ConcentratedFuzzySet : public FuzzySet {
private:
    FuzzySet* fuzzySet;
public:
    explicit ConcentratedFuzzySet(FuzzySet* fuzzySet);

    Domain* getDomain() override;

    double getValueAt(DomainElement el) override;
};

class DilatedFuzzySet : public FuzzySet {
private:
    FuzzySet* fuzzySet;
public:
    explicit DilatedFuzzySet(FuzzySet* fuzzySet);

    Domain* getDomain() override;

    double getValueAt(DomainElement el) override;
};

#endif //FUZZY_INFERENCE_SYSTEM_FUZZYSET_H
