//
// Created by vkolobara on 12/26/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_FUZZYSET_H
#define FUZZY_INFERENCE_SYSTEM_FUZZYSET_H


#include "../domain/Domain.h"
#include "MembershipFunction.h"

class FuzzySet {

public:
    virtual shared_ptr<Domain> getDomain() = 0;

    virtual double getValueAt(DomainElement el) = 0;

    static shared_ptr<FuzzySet>
    combine(shared_ptr<FuzzySet> set1, shared_ptr<FuzzySet> set2, shared_ptr<BinaryFunction> f);
};

class CalculatedFuzzySet : public FuzzySet {
private:
    shared_ptr<MembershipFunction> function;
    shared_ptr<Domain> domain;
public:
    CalculatedFuzzySet(const shared_ptr<MembershipFunction> &function, const shared_ptr<Domain> &domain);

    shared_ptr<Domain> getDomain() override;

    double getValueAt(DomainElement el) override;
};

class MutableFuzzySet : public FuzzySet {
private:
    vector<double> memberships;
    shared_ptr<Domain> domain;
public:
    explicit MutableFuzzySet(const shared_ptr<Domain> &domain);

    shared_ptr<Domain> getDomain() override;

    double getValueAt(DomainElement el) override;

    void set(DomainElement el, double mu);
};

class NegatedFuzzySet : public FuzzySet {
private:
    shared_ptr<FuzzySet> fuzzySet;
    shared_ptr<BaseOperator::Complement> complement;
public:
    NegatedFuzzySet(const shared_ptr<FuzzySet> &fuzzySet, const shared_ptr<BaseOperator::Complement> &complement);

    shared_ptr<Domain> getDomain() override;

    double getValueAt(DomainElement el) override;
};

class ConcentratedFuzzySet : public FuzzySet {
private:
    shared_ptr<FuzzySet> fuzzySet;
public:
    explicit ConcentratedFuzzySet(const shared_ptr<FuzzySet> &fuzzySet);

    shared_ptr<Domain> getDomain() override;

    double getValueAt(DomainElement el) override;
};

class DilatedFuzzySet : public FuzzySet {
private:
    shared_ptr<FuzzySet> fuzzySet;
public:
    explicit DilatedFuzzySet(const shared_ptr<FuzzySet> &fuzzySet);

    shared_ptr<Domain> getDomain() override;

    double getValueAt(DomainElement el) override;
};

#endif //FUZZY_INFERENCE_SYSTEM_FUZZYSET_H
