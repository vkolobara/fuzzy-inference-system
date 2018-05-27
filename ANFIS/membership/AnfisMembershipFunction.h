//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_ANFISMEMBERSHIPFUNCTION_H
#define FUZZY_ANFISMEMBERSHIPFUNCTION_H

#include <vector>

using namespace std;

class AnfisMembershipFunction {
public:
    virtual double valueAt(double x) = 0;
    virtual int getNumParameters() = 0;
    virtual void updateParameters(vector<double> params) = 0;
};




#endif //FUZZY_ANFISMEMBERSHIPFUNCTION_H
