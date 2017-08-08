//
// Created by vkolobara on 8/7/17.
//

#include <cmath>
#include "MembershipFunctions.h"

namespace LinearMembershipFunction {

    /*
     * Usually, Gamma membership function is used in 'large', 'high' concepts.
     *
     */
    class GammaMembershipFunction : public MembershipFunction {
    private:
        double alpha, beta;
    public:
        GammaMembershipFunction(double alpha, double beta) : alpha{alpha}, beta{beta} {
            // CHECK alpha < beta
        }

        ~GammaMembershipFunction() {}

        double valueAt(const double &x) {
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
    class LambdaMembershipFunction : public MembershipFunction {
    private:
        double alpha, beta, gamma;
    public:
        LambdaMembershipFunction(double alpha, double beta, double gamma) : alpha{alpha}, beta{beta}, gamma{gamma} {
            // CHECK alpha < beta < gamma
        }

        ~LambdaMembershipFunction() {}

        double valueAt(const double &x) {
            if (x < alpha || x >= gamma) return 0;
            else if (x < beta && x >= alpha) return (x - alpha) / (beta - alpha);
            else return (gamma - x) / (gamma - beta);
        }

    };

    /*
     * L membership function is used as the exact opposite to the gamma function. It represents 'low' concept.
     */
    class LMembershipFunction : public GammaMembershipFunction {
    public:

        LMembershipFunction(double alpha, double beta) : GammaMembershipFunction(alpha, beta) {}

        double calculateValue(const double &x) {
            return 1 - GammaMembershipFunction::valueAt(x);
        }
    };

    /*
     * Similar to the lambda function, except there is no one value which is the center, there is an continuos interval
     * where the center is.
     */
    class PiMembershipFunction : public MembershipFunction {
    private:
        double alpha, beta, gamma, delta;
    public:
        PiMembershipFunction(double alpha, double beta, double gamma, double delta) : alpha(alpha), beta(beta),
                                                                                      gamma(gamma), delta(delta) {
            // CHECK alpha < beta < gamma < delta
        }

        ~PiMembershipFunction() {}

        double valueAt(const double &x) {
            if (x < alpha || x >= delta) return 0;
            else if (x < gamma && x >= beta) return 1;
            else if (x < beta && x >= alpha) return (x - alpha) / (beta - alpha);
            else return (delta - x) / (delta - gamma);
        }
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
        SMembershipFunction(double alpha, double beta, double gamma) : alpha{alpha}, beta{beta}, gamma{gamma} {
            // CHECK alpha < beta < gamma
        }

        ~SMembershipFunction() {}

        double valueAt(const double &x) {
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
    class GaussMembershipFunction : public MembershipFunction {
    private:
        double mu, sigma;
    public:
        GaussMembershipFunction(double mu, double sigma) : mu(mu), sigma(sigma) {}

        ~GaussMembershipFunction() {}

        double valueAt(const double &x) {
            double exponent = (x - mu) / sigma;
            return exp(-exponent * exponent);
        }
    };

    /*
     * Sigmoidal membership function. c decides where 0.5 value is, a how steep the climb is.
     */
    class SigmoidMembershipFunction : public MembershipFunction {
    private:
        double a, c;
    public:
        SigmoidMembershipFunction(double a, double c) : a(a), c(c) {}

        ~SigmoidMembershipFunction() {}

        double valueAt(const double &x) {
            return 1 / (1 + exp(-a * (x - c)));
        }
    };

    /*
     * Pi membership function. gamma represents the center, beta the bell width.
     */
    class PiMembershipFunction : public MembershipFunction {
    private:
        double beta, gamma;
    public:
        PiMembershipFunction(double beta, double gamma) : beta(beta), gamma(gamma) {}

        ~PiMembershipFunction() {}

        double valueAt(const double &x) {
            MembershipFunction *f = nullptr;
            if (x < gamma) {
                f = new SMembershipFunction(gamma - beta, gamma - beta / 2, gamma);
                return f->valueAt(x);
            } else {
                f = new SMembershipFunction(gamma, gamma + beta / 2, gamma + beta);
                return 1 - f->valueAt(x);
            }

        }
    };

    /*
     * Exponentiallike membership function. mu represents the center, k the bell width.
     * This function is nowhere equal to 0.
     */
    class ExponentialLikeMembershipFunction : public MembershipFunction {
    private:
        double mu, k;
    public:
        ExponentialLikeMembershipFunction(double mu, double k) : mu(mu), k(k) {}

        virtual ~ExponentialLikeMembershipFunction() {

        }

        double valueAt(const double &x) {
            return 1 / (1 + k * (x - mu) * (x - mu));
        }
    };

}