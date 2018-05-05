//
// Created by vkolobara on 8/13/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_LANGUAGETERM_H
#define FUZZY_INFERENCE_SYSTEM_LANGUAGETERM_H


#include <string>
#include <map>
#include <memory>
#include <stdexcept>
#include <utility>
#include "LanguageTerm.h"

using namespace std;

struct LanguageTerm {
    string name;

    LanguageTerm() = default;

    explicit LanguageTerm(string name): name(std::move(name)) {}

    virtual double membership(const double &x) = 0;
    virtual double midpoint() = 0;
};

namespace LinearLanguageTerm {
    /*
     * Usually, Gamma membership function is used in 'large', 'high' concepts.
     *
     */
    struct GammaLanguageTerm : public LanguageTerm {
        double alpha, beta;
        GammaLanguageTerm(const string &name, double alpha, double beta);

        double membership(const double &x) override;
    };

    /*
     * Lambda membership functions is used for the 'around' concept.
     *
     */
    struct LambdaLanguageTerm : public LanguageTerm {
        double alpha, beta, gamma;
        LambdaLanguageTerm(const string &name, double alpha, double beta, double gamma);

        double membership(const double &x) override;

    };

    /*
     * L membership function is used as the exact opposite to the gamma function. It represents 'low' concept.
     */
    struct LLanguageTerm : public LanguageTerm {
        double alpha, beta;

        LLanguageTerm(const string &name, double alpha, double beta);

        double membership(const double &x) override;
    };

    /*
     * Similar to the lambda function, except there is no one value which is the center, there is an interval
     * where the center is.
     */
    struct PiLanguageTerm : public LanguageTerm {
        double alpha, beta, gamma, delta;
        PiLanguageTerm(const string &name, double alpha, double beta, double gamma, double delta);

        double membership(const double &x) override;

        double midpoint() override;
    };
}

namespace SmoothLanguageTerm {

    /*
     * Smooth version of the gamma membership function.
     * Beta should be (alpha + gamma) / 2.
     */
    struct SLanguageTerm : public LanguageTerm {
        double alpha, beta, gamma;
        SLanguageTerm(const string &name, double alpha, double beta, double gamma);

        double membership(const double &x) override;
    };

    /*
     * Gauss membership function. mu is the mean, sigma std deviation.
     */
    struct GaussLanguageTerm : public LanguageTerm {
        double mu, sigma;
        GaussLanguageTerm(const string &name, double mu, double sigma);

        double membership(const double &x) override;
    };

    /*
     * Sigmoidal membership function. c decides where 0.5 value is, a how steep the climb is.
     */
    struct SigmoidLanguageTerm : public LanguageTerm {
        double a, c;
        SigmoidLanguageTerm(const string &name, double a, double c);

        double membership(const double &x) override;
    };

    /*
     * Exponentiallike membership function. mu represents the center, k the bell width.
     * This function is nowhere equal to 0.
     */
    struct ExponentialLikeLanguageTerm : public LanguageTerm {
        double mu, k;
        ExponentialLikeLanguageTerm(const string &name, double mu, double k);

        double membership(const double &x) override;
    };
}


#endif //FUZZY_INFERENCE_SYSTEM_LANGUAGETERM_H