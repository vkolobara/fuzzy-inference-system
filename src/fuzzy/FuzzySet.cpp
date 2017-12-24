//
// Created by vkolobara on 8/7/17.
//

#include <stdexcept>
#include <memory>
#include "FuzzySet.h"

namespace LinearFuzzySet {
    /*
     * Usually, Gamma membership function is used in 'large', 'high' concepts.
     *
     */
    class GammaFuzzySet : public FuzzySet {
    private:
        double alpha, beta;
    public:
        GammaFuzzySet(double alpha, double beta) : alpha{alpha}, beta{beta} {
            if (alpha >= beta) throw std::invalid_argument("Arguments must be: alpha < beta");
        }

        ~GammaFuzzySet() = default;

        double valueAt(const double &x) override {
            if (x < alpha) {
                return 0;
            } else if (x >= beta) {
                return 1;
            } else {
                return (x - alpha) / (beta - alpha);
            }
        }
    };


    /*
     * Lambda membership functions is used for the 'around' concept.
     *
     */
    class LambdaFuzzySet : public FuzzySet {
    private:
        double alpha, beta, gamma;
    public:
        LambdaFuzzySet(double alpha, double beta, double gamma) : alpha{alpha}, beta{beta}, gamma{gamma} {
            if (!(alpha < beta && beta < gamma)) throw std::invalid_argument("Arguments must be: alpha < beta < gamma");
        }

        ~LambdaFuzzySet() = default;

        double valueAt(const double &x) override {
            if (x < alpha || x >= gamma) return 0;
            else if (x < beta && x >= alpha) return (x - alpha) / (beta - alpha);
            else return (gamma - x) / (gamma - beta);
        }

    };

    /*
     * L membership function is used as the exact opposite to the gamma function. It represents 'low' concept.
     */
    class LFuzzySet : public FuzzySet {
    private:
        double alpha, beta;
    public:

        LFuzzySet(double alpha, double beta) : alpha(alpha), beta(beta) {
            if (alpha >= beta) throw std::invalid_argument("Arguments must be: alpha < beta");
        }

        ~LFuzzySet() = default;;

        double valueAt(const double &x) override {
            if (x < alpha) return 1;
            else if (x >= beta) return 0;
            else return (beta - x) / (beta - alpha);
        }
    };

    /*
     * Similar to the lambda function, except there is no one value which is the center, there is an interval
     * where the center is.
     */
    class PiFuzzySet : public FuzzySet {
    private:
        double alpha, beta, gamma, delta;
    public:
        PiFuzzySet(double alpha, double beta, double gamma, double delta) : alpha(alpha), beta(beta),
                                                                            gamma(gamma), delta(delta) {
            if (!(alpha < beta && beta < gamma && gamma < delta))
                throw std::invalid_argument("Arguments must be: alpha < beta < gamma < delta");
        }

        ~PiFuzzySet() = default;

        double valueAt(const double &x) override {
            if (x < alpha || x >= delta) return 0;
            else if (x < gamma && x >= beta) return 1;
            else if (x < beta && x >= alpha) return (x - alpha) / (beta - alpha);
            else return (delta - x) / (delta - gamma);
        }
    };
}

namespace SmoothFuzzySet {

    /*
     * Smooth version of the gamma membership function.
     * Beta should be (alpha + gamma) / 2.
     */
    class SFuzzySet : public FuzzySet {
    private:
        double alpha, beta, gamma;
    public:
        SFuzzySet(double alpha, double beta, double gamma) : alpha{alpha}, beta{beta}, gamma{gamma} {
            if (!(alpha < beta && beta < gamma)) throw std::invalid_argument("Arguments must be: alpha < beta < gamma");
        }

        ~SFuzzySet() = default;

        double valueAt(const double &x) override {
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
    };

    /*
     * Gauss membership function. mu is the mean, sigma std deviation.
     */
    class GaussFuzzySet : public FuzzySet {
    private:
        double mu, sigma;
    public:
        GaussFuzzySet(double mu, double sigma) : mu(mu), sigma(sigma) {}

        ~GaussFuzzySet() = default;

        double valueAt(const double &x) override {
            double exponent = (x - mu) / sigma;
            return exp(-exponent * exponent);
        }
    };

    /*
     * Sigmoidal membership function. c decides where 0.5 value is, a how steep the climb is.
     */
    class SigmoidFuzzySet : public FuzzySet {
    private:
        double a, c;
    public:
        SigmoidFuzzySet(double a, double c) : a(a), c(c) {}

        ~SigmoidFuzzySet() = default;

        double valueAt(const double &x) override {
            return 1.0 / (1 + exp(-a * (x - c)));
        }
    };

    /*
     * Exponentiallike membership function. mu represents the center, k the bell width.
     * This function is nowhere equal to 0.
     */
    class ExponentialLikeFuzzySet : public FuzzySet {
    private:
        double mu, k;
    public:
        ExponentialLikeFuzzySet(double mu, double k) : mu(mu), k(k) {}

        virtual ~ExponentialLikeFuzzySet() {

        }

        double valueAt(const double &x) {
            return 1.0 / (1 + k * (x - mu) * (x - mu));
        }
    };
}