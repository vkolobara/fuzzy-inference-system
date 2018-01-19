//
// Created by vkolobara on 1/3/18.
//

#include <random>
#include "GaussMembershipFunction.h"

double GaussMembershipFunction::valueAt(double x) {
    return f->valueAt(x);
}

int GaussMembershipFunction::getNumParameters() {
    return 2;
}

void GaussMembershipFunction::updateParameters(vector<double> params) {
    f->setMu(f->getMu()-params[0]);
    f->setSigma(f->getSigma()-params[1]);
}

vector<double> GaussMembershipFunction::gradients(double x) {
    auto mu = f->getMu();
    auto sigma = f->getSigma();

    double gradF = valueAt(x);
    double gradSq = (mu - x) / sigma;

    double gradMu = gradF * gradSq * (-1/(2*sigma));
    double gradSigma = gradF * gradSq * (-1 * (x-mu) / (2*sigma*sigma));

    return vector<double>{gradMu, gradSigma};
}

GaussMembershipFunction::GaussMembershipFunction() {
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_real_distribution<double> uniform_dist(-1, 1);
    f = new SmoothMembershipFunction::GaussMembershipFunction(uniform_dist(e1), uniform_dist(e1));
}

GaussMembershipFunction::~GaussMembershipFunction() {
    delete f;

}
