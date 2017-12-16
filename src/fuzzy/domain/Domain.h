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
	virtual int getCardinality() = 0;
    virtual int getNumberOfComponents() = 0;
	virtual shared_ptr<Domain> getComponent(int index) = 0;
    virtual DomainElement getElementAt(int index) = 0;
    virtual int indexOfElement (DomainElement element) = 0;
};
#endif //FUZZY_INFERENCE_SYSTEM_DOMAIN_H
