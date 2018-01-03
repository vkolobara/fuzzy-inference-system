//
// Created by vkolobara on 8/7/17.
//

#include <stdexcept>
#include <memory>
#include "MembershipFunction.h"

namespace LinearMembershipFunction {

    GammaMembershipFunction::GammaMembershipFunction(double alpha, double beta) : alpha{alpha}, beta{beta} {
        if (alpha >= beta) throw std::invalid_argument("Arguments must be: alpha < beta");
    }

    double GammaMembershipFunction::valueAt(const double &x) {
        if (x < alpha) {
            return 0;
        } else if (x >= beta) {
            return 1;
        } else {
            return (x - alpha) / (beta - alpha);
        }
    }

    LambdaMembershipFunction::LambdaMembershipFunction(double alpha, double beta, double gamma) : alpha{alpha},
                                                                                                  beta{beta},
                                                                                                  gamma{gamma} {
        if (!(alpha < beta && beta < gamma)) throw std::invalid_argument("Arguments must be: alpha < beta < gamma");
    }

    double LambdaMembershipFunction::valueAt(const double &x) {
        if (x < alpha || x >= gamma) return 0;
        else if (x < beta && x >= alpha) return (x - alpha) / (beta - alpha);
        else return (gamma - x) / (gamma - beta);
    }


    LMembershipFunction::LMembershipFunction(double alpha, double beta) : alpha(alpha), beta(beta) {
        if (alpha >= beta) throw std::invalid_argument("Arguments must be: alpha < beta");
    }

    double LMembershipFunction::valueAt(const double &x) {
        if (x < alpha) return 1;
        else if (x >= beta) return 0;
        else return (beta - x) / (beta - alpha);
    }

    PiMembershipFunction::PiMembershipFunction(double alpha, double beta, double gamma, double delta) : alpha(alpha),
                                                                                                        beta(beta),
                                                                                                        gamma(gamma),
                                                                                                        delta(delta) {
        if (!(alpha < beta && beta < gamma && gamma < delta))
            throw std::invalid_argument("Arguments must be: alpha < beta < gamma < delta");
    }

    double PiMembershipFunction::valueAt(const double &x) {
        if (x < alpha || x >= delta) return 0;
        else if (x < gamma && x >= beta) return 1;
        else if (x < beta && x >= alpha) return (x - alpha) / (beta - alpha);
        else return (delta - x) / (delta - gamma);
    }
}

namespace SmoothMembershipFunction {

    SMembershipFunction::SMembershipFunction(double alpha, double beta, double gamma) : alpha{alpha}, beta{beta},
                                                                                        gamma{gamma} {
        if (!(alpha < beta && beta < gamma)) throw std::invalid_argument("Arguments must be: alpha < beta < gamma");
    }

    double SMembershipFunction::valueAt(const double &x) {
        if (x < alpha) return 0;
        else if (x >= gamma) return 1;
        else if (x < beta && x >= alpha) {
            double f = (x - alpha) / (gamma - alpha);
            return 2 * f * f;
        } else {
            double f = (x - gamma) / (gamma - alpha);
            return 1 - 2 * f * f;
        }
    }

    GaussMembershipFunction::GaussMembershipFunction(double mu, double sigma) : mu(mu), sigma(sigma) {}


    double GaussMembershipFunction::valueAt(const double &x) {
        double exponent = (x - mu) / (2*sigma);
        return exp(-(exponent * exponent));
    }

    void GaussMembershipFunction::setMu(double mu) {
        GaussMembershipFunction::mu = mu;
    }

    void GaussMembershipFunction::setSigma(double sigma) {
        GaussMembershipFunction::sigma = sigma;
    }

    double GaussMembershipFunction::getMu() const {
        return mu;
    }

    double GaussMembershipFunction::getSigma() const {
        return sigma;
    }

    SigmoidMembershipFunction::SigmoidMembershipFunction(double a, double c) : a(a), c(c) {}

    double SigmoidMembershipFunction::valueAt(const double &x) {
        return 1.0 / (1 + exp(-a * (x - c)));
    }

    double SigmoidMembershipFunction::getA() const {
        return a;
    }

    void SigmoidMembershipFunction::setA(double a) {
        SigmoidMembershipFunction::a = a;
    }

    double SigmoidMembershipFunction::getC() const {
        return c;
    }

    void SigmoidMembershipFunction::setC(double c) {
        SigmoidMembershipFunction::c = c;
    }

    ExponentialLikeMembershipFunction::ExponentialLikeMembershipFunction(double mu, double k) : mu(mu), k(k) {}

    double ExponentialLikeMembershipFunction::valueAt(const double &x) {
        return 1.0 / (1 + k * (x - mu) * (x - mu));
    }
}