//
// Created by vkolobara on 1/3/18.
//

#include "GaussMembershipFunction.h"

double GaussMembershipFunction::valueAt(double x) {
    return f->valueAt(x);
}

int GaussMembershipFunction::getNumParameters() {
    return 2;
}

void GaussMembershipFunction::updateParameters(vector<double> params) {
    f->setMu(params[0]);
    f->setSigma(params[1]);
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
    f = make_shared<SmoothMembershipFunction::GaussMembershipFunction>(0, 1);
}
