//
// Created by vkolobara on 8/7/17.
//

#ifndef DIPLOMSKI_MEMBERSHIP_FUNCTIONS_H
#define DIPLOMSKI_MEMBERSHIP_FUNCTIONS_H

class MembershipFunction {
public:
    virtual double calculateValue(const double& x);
};

#endif //DIPLOMSKI_MEMBERSHIP_FUNCTIONS_H