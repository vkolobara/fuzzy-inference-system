//
// Created by vkolobara on 1/3/18.
//

#include <random>
#include "SigmoidMembershipFunction.h"

double SigmoidMembershipFunction::valueAt(double x) {
    return f->valueAt(x);
}

int SigmoidMembershipFunction::getNumParameters() {
    return 2;
}

void SigmoidMembershipFunction::updateParameters(vector<double> params) {
    f->setA(f->getA()-params[0]);
    f->setC(f->getC()-params[1]);
}

vector<double> SigmoidMembershipFunction::gradients(double x) {

    auto a = f->getA();
    auto c = f->getC();

    auto sigmoid = f->valueAt(x);
    auto gradSigmoid = sigmoid * (1 - sigmoid);

    auto gradA = gradSigmoid * -(x-c);
    auto gradC = gradSigmoid * a;

    return vector<double>{gradA, gradC};
}

SigmoidMembershipFunction::SigmoidMembershipFunction() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-1.0, 1.0);
    f = new SmoothMembershipFunction::SigmoidMembershipFunction(dist(mt), dist(mt));
}

SigmoidMembershipFunction::~SigmoidMembershipFunction() {
    delete f;
}
