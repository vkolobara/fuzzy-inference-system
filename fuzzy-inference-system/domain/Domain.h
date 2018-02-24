//
// Created by vkolobara on 8/8/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_DOMAIN_H
#define FUZZY_INFERENCE_SYSTEM_DOMAIN_H

#include "DomainElement.h"
#include <memory>

using namespace std;

class Domain : public enable_shared_from_this<Domain> {
public:
    virtual unsigned int getCardinality() = 0;

    virtual unsigned int getNumberOfComponents() = 0;

    virtual Domain* getComponent(unsigned int index) = 0;

    DomainElement getElementAt(unsigned int index);

    int indexOfElement(DomainElement element);
};

#endif //FUZZY_INFERENCE_SYSTEM_DOMAIN_H
