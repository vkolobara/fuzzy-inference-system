//
// Created by vkolobara on 1/3/18.
//

#include <random>
#include "SigmoidMembershipFunction.h"

double SigmoidMembershipFunction::valueAt(double x) {
    return f->membership(x);
}

int SigmoidMembershipFunction::getNumParameters() {
    return 2;
}

void SigmoidMembershipFunction::updateParameters(vector<double> params) {
    f->a = params[0];
    f->c = params[1];
}

SigmoidMembershipFunction::SigmoidMembershipFunction() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);
    f = make_shared<SmoothLanguageTerm::SigmoidLanguageTerm>("name", dist(mt), dist(mt));
}
