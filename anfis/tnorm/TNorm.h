//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_TNORM_H
#define FUZZY_TNORM_H

#include <vector>

using namespace std;

class TNorm {
public:
    virtual double calculateValue(vector<double> inputs) = 0;
};

class ProductTNorm : public TNorm {
public:
    double calculateValue(vector<double> inputs) override;
};


#endif //FUZZY_TNORM_H
