//
// Created by vkolobara on 8/7/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_MEMBERSHIP_FUNCTIONS_H
#define FUZZY_INFERENCE_SYSTEM_MEMBERSHIP_FUNCTIONS_H

#include "Operators.h"
#include <utility>
#include <vector>
#include <initializer_list>
#include <memory>
#include <cmath>

using namespace std;

class FuzzySet {
public:
    virtual double valueAt(const double &x) = 0;
};


class DilatedFuzzySet : public FuzzySet {
private:
    shared_ptr<FuzzySet> f;
public:
    explicit DilatedFuzzySet(shared_ptr<FuzzySet> f) : f(std::move(f)) {}

    double valueAt(const double &x) override {
        return sqrt(f->valueAt(x));
    }

};

class ConcentratedFuzzySet : public FuzzySet {
private:
    shared_ptr<FuzzySet> f;
public:
    explicit ConcentratedFuzzySet(shared_ptr<FuzzySet> f) : f(std::move(f)) {}

    double valueAt(const double &x) override {
        return pow(f->valueAt(x), 2);
    }

};

class ContrastIntensificationFuzzySet : public FuzzySet {
private:
    shared_ptr<FuzzySet> f;
public:
    explicit ContrastIntensificationFuzzySet(shared_ptr<FuzzySet> f) : f(std::move(f)) {}

    double valueAt(const double &x) override {
        double value = f->valueAt(x);
        if (value <= 0.5) {
            value = 2 * value * value;
        } else {
            value = 1 - 2 * pow(1 - value, 2);
        }
        return value;
    }

};

class UnaryOpFuzzySet : public FuzzySet {
protected:
    shared_ptr<FuzzySet> f;
    shared_ptr<UnaryFunction> op;
public:
    UnaryOpFuzzySet(shared_ptr<FuzzySet> f, shared_ptr<UnaryFunction> op) :f(std::move(f)), op(std::move(op)) {}

    double valueAt(const double &x) override {
        return op->calculateValue(f->valueAt(x));
    }
};

class MultipleOpFuzzySet : public FuzzySet {
protected:
    vector<shared_ptr<FuzzySet>> fuzzySets;
    shared_ptr<BinaryFunction> op;
public:
    MultipleOpFuzzySet(vector<shared_ptr<FuzzySet>> fuzzySets, shared_ptr<BinaryFunction> op) : fuzzySets(
            std::move(fuzzySets)), op(std::move(op)) {}

    double valueAt(const double &x) override {

        auto val = fuzzySets[0]->valueAt(x);

        for (int i=1; i<fuzzySets.size(); i++) {
            val = op->calculateValue(val, fuzzySets[i]->valueAt(x));
        }
        return val;
    }
};

class AndFuzzySet : public MultipleOpFuzzySet {
public:
    AndFuzzySet(const vector<shared_ptr<FuzzySet>> &fuzzySets,
                const shared_ptr<BaseOperator::TNorm> &op) : MultipleOpFuzzySet(fuzzySets, op) {}
};

class OrFuzzySet : public MultipleOpFuzzySet {
public:
    OrFuzzySet(const vector<shared_ptr<FuzzySet>> &fuzzySets,
               const shared_ptr<BaseOperator::SNorm> &op) : MultipleOpFuzzySet(fuzzySets, op) {}
};

class NotFuzzySet : public UnaryOpFuzzySet {
public:
    NotFuzzySet(const shared_ptr<FuzzySet> &f, const shared_ptr<BaseOperator::Complement> &op) : UnaryOpFuzzySet(f, op){};
};

#endif //FUZZY_INFERENCE_SYSTEM_MEMBERSHIP_FUNCTIONS_H