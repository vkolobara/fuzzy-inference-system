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

class MembershipFunction {
public:
    virtual double valueAt(const double &x) = 0;
};


class DilatedMembershipFunction : public MembershipFunction {
private:
    shared_ptr<MembershipFunction> f;
public:
    explicit DilatedMembershipFunction(shared_ptr<MembershipFunction> f) : f(std::move(f)) {}

    double valueAt(const double &x) override {
        return sqrt(f->valueAt(x));
    }

};

class ConcentratedMembershipFunction : public MembershipFunction {
private:
    shared_ptr<MembershipFunction> f;
public:
    explicit ConcentratedMembershipFunction(shared_ptr<MembershipFunction> f) : f(std::move(f)) {}

    double valueAt(const double &x) override {
        return pow(f->valueAt(x), 2);
    }

};

class ContrastIntensificationMembershipFunction : public MembershipFunction {
private:
    shared_ptr<MembershipFunction> f;
public:
    explicit ContrastIntensificationMembershipFunction(shared_ptr<MembershipFunction> f) : f(std::move(f)) {}

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

class UnaryOpMembershipFunction : public MembershipFunction {
protected:
    shared_ptr<MembershipFunction> f;
    shared_ptr<UnaryFunction> op;
public:
    UnaryOpMembershipFunction(shared_ptr<MembershipFunction> f, shared_ptr<UnaryFunction> op) :f(std::move(f)), op(std::move(op)) {}

    double valueAt(const double &x) override {
        return op->calculateValue(f->valueAt(x));
    }
};

class MultipleOpMembershipFunction : public MembershipFunction {
protected:
    vector<shared_ptr<MembershipFunction>> membershipFunctions;
    shared_ptr<BinaryFunction> op;
public:
    MultipleOpMembershipFunction(vector<shared_ptr<MembershipFunction>> membershipFunctions, shared_ptr<BinaryFunction> op) : membershipFunctions(
            std::move(membershipFunctions)), op(std::move(op)) {}

    double valueAt(const double &x) override {

        auto val = membershipFunctions[0]->valueAt(x);

        for (int i=1; i<membershipFunctions.size(); i++) {
            val = op->calculateValue(val, membershipFunctions[i]->valueAt(x));
        }
        return val;
    }
};

class AndMembershipFunction : public MultipleOpMembershipFunction {
public:
    AndMembershipFunction(const vector<shared_ptr<MembershipFunction>> &membershipFunctions,
                const shared_ptr<BaseOperator::TNorm> &op) : MultipleOpMembershipFunction(membershipFunctions, op) {}
};

class OrMembershipFunction : public MultipleOpMembershipFunction {
public:
    OrMembershipFunction(const vector<shared_ptr<MembershipFunction>> &membershipFunctions,
               const shared_ptr<BaseOperator::SNorm> &op) : MultipleOpMembershipFunction(membershipFunctions, op) {}
};

class NotMembershipFunction : public UnaryOpMembershipFunction {
public:
    NotMembershipFunction(const shared_ptr<MembershipFunction> &f, const shared_ptr<BaseOperator::Complement> &op) : UnaryOpMembershipFunction(f, op){};
};

#endif //FUZZY_INFERENCE_SYSTEM_MEMBERSHIP_FUNCTIONS_H