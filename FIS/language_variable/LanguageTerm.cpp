//
// Created by vkolobara on 8/7/17.
//

#include <stdexcept>
#include <memory>
#include <cmath>
#include "LanguageTerm.h"

namespace LinearLanguageTerm {

    GammaLanguageTerm::GammaLanguageTerm(const string &name, double alpha, double beta) : LanguageTerm(name), alpha{alpha}, beta{beta} {
        if (alpha >= beta) throw std::invalid_argument("Arguments must be: alpha < beta");
    }

    double GammaLanguageTerm::membership(const double &x) {
        if (x < alpha) {
            return 0;
        } else if (x >= beta) {
            return 1;
        } else {
            return (x - alpha) / (beta - alpha);
        }
    }

    LambdaLanguageTerm::LambdaLanguageTerm(const string &name, double alpha, double beta, double gamma) : LanguageTerm(name), alpha{alpha},
                                                                                                  beta{beta},
                                                                                                  gamma{gamma} {
        if (!(alpha < beta && beta < gamma)) throw std::invalid_argument("Arguments must be: alpha < beta < gamma");
    }

    double LambdaLanguageTerm::membership(const double &x) {
        if (x < alpha || x >= gamma) return 0;
        else if (x < beta && x >= alpha) return (x - alpha) / (beta - alpha);
        else return (gamma - x) / (gamma - beta);
    }

    LLanguageTerm::LLanguageTerm(const string &name, double alpha, double beta) : LanguageTerm(name), alpha(alpha), beta(beta) {
        if (alpha >= beta) throw std::invalid_argument("Arguments must be: alpha < beta");
    }

    double LLanguageTerm::membership(const double &x) {
        if (x < alpha) return 1;
        else if (x >= beta) return 0;
        else return (beta - x) / (beta - alpha);
    }

    PiLanguageTerm::PiLanguageTerm(const string &name, double alpha, double beta, double gamma, double delta) : LanguageTerm(name), alpha(alpha),
                                                                                                        beta(beta),
                                                                                                        gamma(gamma),
                                                                                                        delta(delta) {
        if (!(alpha < beta && beta < gamma && gamma < delta))
            throw std::invalid_argument("Arguments must be: alpha < beta < gamma < delta");
    }

    double PiLanguageTerm::membership(const double &x) {
        if (x < alpha || x >= delta) return 0;
        else if (x < gamma && x >= beta) return 1;
        else if (x < beta && x >= alpha) return (x - alpha) / (beta - alpha);
        else return (delta - x) / (delta - gamma);
    }

    double PiLanguageTerm::midpoint() {
        return (gamma + beta) / 2;
    }

}

namespace SmoothLanguageTerm {

    SLanguageTerm::SLanguageTerm(const string &name, double alpha, double beta, double gamma) : LanguageTerm(name), alpha{alpha}, beta{beta},
                                                                                        gamma{gamma} {
        if (!(alpha < beta && beta < gamma)) throw std::invalid_argument("Arguments must be: alpha < beta < gamma");
    }

    double SLanguageTerm::membership(const double &x) {
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

    GaussLanguageTerm::GaussLanguageTerm(const string &name, double mu, double sigma) : LanguageTerm(name), mu(mu), sigma(sigma) {}


    double GaussLanguageTerm::membership(const double &x) {
        double exponent = (x - mu) / (2*sigma);
        return exp(-(exponent * exponent));
    }

    double GaussLanguageTerm::midpoint() {
        return mu;
    }

    SigmoidLanguageTerm::SigmoidLanguageTerm(const string &name, double a, double c) : LanguageTerm(name), a(a), c(c) {}

    double SigmoidLanguageTerm::membership(const double &x) {
        return 1.0 / (1 + exp(a * (x - c)));
    }

    double SigmoidLanguageTerm::midpoint() {
        return a;
    }

    ExponentialLikeLanguageTerm::ExponentialLikeLanguageTerm(const string &name, double mu, double k) : LanguageTerm(name), mu(mu), k(k) {}

    double ExponentialLikeLanguageTerm::membership(const double &x) {
        return 1.0 / (1 + k * (x - mu) * (x - mu));
    }
}

