//
// Created by vkolobara on 8/8/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_DOMAIN_H
#define FUZZY_INFERENCE_SYSTEM_DOMAIN_H

#include "DomainElement.h"
#include <memory>

using namespace std;

class Domain : public enable_shared_from_this<Domain>{
public:
	virtual uint getCardinality() = 0;
    virtual unsigned long getNumberOfComponents() = 0;
	virtual shared_ptr<Domain> getComponent(uint index) = 0;
    virtual DomainElement getElementAt(uint index) = 0;
    virtual uint indexOfElement (DomainElement element) = 0;
};
#endif //FUZZY_INFERENCE_SYSTEM_DOMAIN_H
