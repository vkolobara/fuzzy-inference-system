//
// Created by vkolobara on 8/7/17.
//

#include "MembershipFunctions.h"

class GammaMembershipFunction : public MembershipFunction {
private:
    double alpha, beta;
 public:
    GammaMembershipFunction(double alpha, double beta) :alpha{alpha}, beta{beta}{
        // CHECK alpha < beta
    }

    ~GammaMembershipFunction(){}

    double calculateValue(const double &x) {
        if (x < alpha) {
            return 0;
        } else if (x >= beta) {
            return 1;
        } else {
            return (x - alpha) / (beta - alpha);
        }
    }
};


class LambdaMembershipFunction : public MembershipFunction {
private:
    double alpha, beta, gamma;
public:
    LambdaMembershipFunction(double alpha, double beta, double gamma) :alpha{alpha}, beta{beta}, gamma{gamma}{
        // CHECK alpha < beta < gamma
    }
    ~LambdaMembershipFunction(){}

    double calculateValue(const double &x) {
        if (x < alpha || x >= gamma) return 0;
        else if (x < beta && x >= alpha) return (x - alpha) / (beta - alpha);
        else return (gamma - x) / (gamma - beta);
    }

};

class LMembershipFunction : public GammaMembershipFunction {
public:

    LMembershipFunction(double alpha, double beta) : GammaMembershipFunction(alpha, beta) {}

    double calculateValue(const double &x) {
        return 1 - GammaMembershipFunction::calculateValue(x);
    }
};

class PiMembershipFunction : public MembershipFunction {
private:
    double alpha, beta, gamma, delta;
public:
    PiMembershipFunction(double alpha, double beta, double gamma, double delta) : alpha(alpha), beta(beta),
                                                                                  gamma(gamma), delta(delta) {
        // CHECK alpha < beta < gamma < delta
    }

    ~PiMembershipFunction() {}

    double calculateValue(const double &x) {
        if (x < alpha || x >= delta) return 0;
        else if (x < gamma && x >=beta) return 1;
        else if (x < beta && x >= alpha) return (x - alpha) / (beta - alpha);
        else return (delta - x) / (delta - gamma);
    }
};
