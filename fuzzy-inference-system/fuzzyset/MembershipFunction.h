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
    UnaryOpMembershipFunction(shared_ptr<MembershipFunction> f, shared_ptr<UnaryFunction> op) : f(std::move(f)),
                                                                                                op(std::move(op)) {}

    double valueAt(const double &x) override {
        return op->calculateValue(f->valueAt(x));
    }
};

class MultipleOpMembershipFunction : public MembershipFunction {
protected:
    vector<shared_ptr<MembershipFunction>> membershipFunctions;
    shared_ptr<BinaryFunction> op;
public:
    MultipleOpMembershipFunction(vector<shared_ptr<MembershipFunction>> membershipFunctions,
                                 shared_ptr<BinaryFunction> op) : membershipFunctions(
            std::move(membershipFunctions)), op(std::move(op)) {}

    double valueAt(const double &x) override {

        auto val = membershipFunctions[0]->valueAt(x);

        for (int i = 1; i < membershipFunctions.size(); i++) {
            val = op->calculateValue(val, membershipFunctions[i]->valueAt(x));
        }
        return val;
    }
};

class AndMembershipFunction : public MultipleOpMembershipFunction {
public:
    AndMembershipFunction(const vector<shared_ptr<MembershipFunction>> &membershipFunctions,
                          const shared_ptr<BaseOperator::TNorm> &op) : MultipleOpMembershipFunction(membershipFunctions,
                                                                                                    op) {}
};

class OrMembershipFunction : public MultipleOpMembershipFunction {
public:
    OrMembershipFunction(const vector<shared_ptr<MembershipFunction>> &membershipFunctions,
                         const shared_ptr<BaseOperator::SNorm> &op) : MultipleOpMembershipFunction(membershipFunctions,
                                                                                                   op) {}
};

class NotMembershipFunction : public UnaryOpMembershipFunction {
public:
    NotMembershipFunction(const shared_ptr<MembershipFunction> &f, const shared_ptr<BaseOperator::Complement> &op)
            : UnaryOpMembershipFunction(f, op) {};
};

//
// Created by vkolobara on 8/7/17.
//

#include <stdexcept>
#include <memory>
#include "MembershipFunction.h"

namespace LinearMembershipFunction {
    /*
     * Usually, Gamma membership function is used in 'large', 'high' concepts.
     *
     */
    class GammaMembershipFunction : public MembershipFunction {
    private:
        double alpha, beta;
    public:
        GammaMembershipFunction(double alpha, double beta);

        ~GammaMembershipFunction() = default;

        double valueAt(const double &x);
    };


    /*
     * Lambda membership functions is used for the 'around' concept.
     *
     */
    class LambdaMembershipFunction : public MembershipFunction {
    private:
        double alpha, beta, gamma;
    public:
        LambdaMembershipFunction(double alpha, double beta, double gamma);

        ~LambdaMembershipFunction() = default;

        double valueAt(const double &x) override;

    };

    /*
     * L membership function is used as the exact opposite to the gamma function. It represents 'low' concept.
     */
    class LMembershipFunction : public MembershipFunction {
    private:
        double alpha, beta;
    public:

        LMembershipFunction(double alpha, double beta);

        ~LMembershipFunction() = default;

        double valueAt(const double &x) override;
    };

    /*
     * Similar to the lambda function, except there is no one value which is the center, there is an interval
     * where the center is.
     */
    class PiMembershipFunction : public MembershipFunction {
    private:
        double alpha, beta, gamma, delta;
    public:
        PiMembershipFunction(double alpha, double beta, double gamma, double delta);

        ~PiMembershipFunction() = default;

        double valueAt(const double &x) override;
    };
}

namespace SmoothMembershipFunction {

    /*
     * Smooth version of the gamma membership function.
     * Beta should be (alpha + gamma) / 2.
     */
    class SMembershipFunction : public MembershipFunction {
    private:
        double alpha, beta, gamma;
    public:
        SMembershipFunction(double alpha, double beta, double gamma);

        ~SMembershipFunction() = default;

        double valueAt(const double &x) override;
    };

    /*
     * Gauss membership function. mu is the mean, sigma std deviation.
     */
    class GaussMembershipFunction : public MembershipFunction {
    private:
        double mu, sigma;
    public:
        GaussMembershipFunction(double mu, double sigma);

        ~GaussMembershipFunction() = default;

        double valueAt(const double &x) override;

        void setMu(double mu);

        void setSigma(double sigma);

        double getMu() const;

        double getSigma() const;
    };

    /*
     * Sigmoidal membership function. c decides where 0.5 value is, a how steep the climb is.
     */
    class SigmoidMembershipFunction : public MembershipFunction {
    private:
        double a, c;
    public:
        SigmoidMembershipFunction(double a, double c);

        ~SigmoidMembershipFunction() = default;

        double valueAt(const double &x) override;

        double getA() const;

        void setA(double a);

        double getC() const;

        void setC(double c);
    };

    /*
     * Exponentiallike membership function. mu represents the center, k the bell width.
     * This function is nowhere equal to 0.
     */
    class ExponentialLikeMembershipFunction : public MembershipFunction {
    private:
        double mu, k;
    public:
        ExponentialLikeMembershipFunction(double mu, double k);

        ~ExponentialLikeMembershipFunction() = default;

        double valueAt(const double &x) override;
    };
}

#endif //FUZZY_INFERENCE_SYSTEM_MEMBERSHIP_FUNCTIONS_H