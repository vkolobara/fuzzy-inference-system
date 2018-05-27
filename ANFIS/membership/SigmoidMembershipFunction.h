//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_SIGMOIDMEMBERSHIPFUNCTION_H
#define FUZZY_SIGMOIDMEMBERSHIPFUNCTION_H


#include "AnfisMembershipFunction.h"
#include "../../FIS/language_variable/LanguageTerm.h"

class SigmoidMembershipFunction : public AnfisMembershipFunction {
private:
    shared_ptr<SmoothLanguageTerm::SigmoidLanguageTerm> f;
public:
    SigmoidMembershipFunction();
    double valueAt(double x) override;

    int getNumParameters() override;

    void updateParameters(vector<double> params) override;
};


#endif //FUZZY_SIGMOIDMEMBERSHIPFUNCTION_H
