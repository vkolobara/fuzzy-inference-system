//
// Created by vkolobara on 8/8/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_DOMAIN_H
#define FUZZY_INFERENCE_SYSTEM_DOMAIN_H

#include <memory>

using namespace std;

class Domain {
public:
    virtual unsigned int getCardinality() = 0;

    virtual double getElementAt(unsigned int index) = 0;

    virtual int indexOfElement(double element) = 0;
};

#endif //FUZZY_INFERENCE_SYSTEM_DOMAIN_H
