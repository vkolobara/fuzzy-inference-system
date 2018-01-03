//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_GAUSSMEMBERSHIPFUNCTION_H
#define FUZZY_GAUSSMEMBERSHIPFUNCTION_H


#include "AnfisMembershipFunction.h"
#include "../../fuzzy-inference-system/fuzzyset/MembershipFunction.h"

class GaussMembershipFunction : public AnfisMembershipFunction{
private:
    shared_ptr<SmoothMembershipFunction::GaussMembershipFunction> f;
public:
    GaussMembershipFunction();

    double valueAt(double x) override;

    int getNumParameters() override;

    void updateParameters(vector<double> params) override;

    vector<double> gradients(double x) override;
};


#endif //FUZZY_GAUSSMEMBERSHIPFUNCTION_H
