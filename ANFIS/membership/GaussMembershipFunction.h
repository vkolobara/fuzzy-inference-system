//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_GAUSSMEMBERSHIPFUNCTION_H
#define FUZZY_GAUSSMEMBERSHIPFUNCTION_H


#include "AnfisMembershipFunction.h"
#include "../../FIS/language_variable/LanguageTerm.h"

class GaussMembershipFunction : public AnfisMembershipFunction{
private:
    shared_ptr<SmoothLanguageTerm::GaussLanguageTerm> f;
public:
    GaussMembershipFunction();

    double valueAt(double x) override;

    int getNumParameters() override;

    void updateParameters(vector<double> params) override;
};


#endif //FUZZY_GAUSSMEMBERSHIPFUNCTION_H
