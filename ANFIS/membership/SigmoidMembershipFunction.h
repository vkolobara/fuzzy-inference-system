//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_SIGMOIDMEMBERSHIPFUNCTION_H
#define FUZZY_SIGMOIDMEMBERSHIPFUNCTION_H


#include "AnfisMembershipFunction.h"
#include "../../FIS/fuzzyset/MembershipFunction.h"

class SigmoidMembershipFunction : public AnfisMembershipFunction {
private:
    SmoothMembershipFunction::SigmoidMembershipFunction* f;
public:
    SigmoidMembershipFunction();
    double valueAt(double x) override;

    virtual ~SigmoidMembershipFunction();

    int getNumParameters() override;

    void updateParameters(vector<double> params) override;

    vector<double> gradients(double x) override;
};


#endif //FUZZY_SIGMOIDMEMBERSHIPFUNCTION_H
