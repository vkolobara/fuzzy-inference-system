//
// Created by vkolobara on 8/8/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_DOMAIN_H
#define FUZZY_INFERENCE_SYSTEM_DOMAIN_H

#include "DomainElement.h"
#include <memory>

using namespace std;

class Domain {
public:
    virtual unsigned int getCardinality() = 0;

    virtual double getElementAt(unsigned int index);

    virtual int indexOfElement(double element);
};

#endif //FUZZY_INFERENCE_SYSTEM_DOMAIN_H
