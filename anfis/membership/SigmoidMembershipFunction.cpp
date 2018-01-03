//
// Created by vkolobara on 1/3/18.
//

#include "SigmoidMembershipFunction.h"

double SigmoidMembershipFunction::valueAt(double x) {
    return f->valueAt(x);
}

int SigmoidMembershipFunction::getNumParameters() {
    return 2;
}

void SigmoidMembershipFunction::updateParameters(vector<double> params) {
    f->setA(params[0]);
    f->setC(params[1]);
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
    f = new SmoothMembershipFunction::SigmoidMembershipFunction(1, 0);
}

SigmoidMembershipFunction::~SigmoidMembershipFunction() {
    delete f;
}
