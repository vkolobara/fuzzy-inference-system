//
// Created by vkolobara on 8/8/17.
//

#ifndef DIPLOMSKI_OPERATORS_H
#define DIPLOMSKI_OPERATORS_H

#include "MembershipFunctions.h"

class BinaryFunction {
public:
    virtual double calculateValue(double a, double b) = 0;
};

class UnaryFunction {
public:
    virtual double calculateValue(double a) = 0;
};

class SNorm : public BinaryFunction {

};

class TNorm : public BinaryFunction {

};

class Complement : public UnaryFunction {
};


#endif //DIPLOMSKI_OPERATORS_H
