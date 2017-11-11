//
// Created by vkolobara on 8/7/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_MEMBERSHIP_FUNCTIONS_H
#define FUZZY_INFERENCE_SYSTEM_MEMBERSHIP_FUNCTIONS_H


class MembershipFunction {
public:
    virtual double valueAt(const double &x) = 0;
};

#endif //FUZZY_INFERENCE_SYSTEM_MEMBERSHIP_FUNCTIONS_H