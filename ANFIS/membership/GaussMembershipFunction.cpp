//
// Created by vkolobara on 1/3/18.
//

#include <random>
#include "GaussMembershipFunction.h"

double GaussMembershipFunction::valueAt(double x) {
    return f->membership(x);
}

int GaussMembershipFunction::getNumParameters() {
    return 2;
}

void GaussMembershipFunction::updateParameters(vector<double> params) {
    f->mu = params[0];
    f->sigma = params[1];
}

GaussMembershipFunction::GaussMembershipFunction() {
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_real_distribution<double> uniform_dist(-1, 1);
    f = make_shared<SmoothLanguageTerm::GaussLanguageTerm>("name", uniform_dist(e1), uniform_dist(e1));
}
