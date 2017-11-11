//
// Created by vkolobara on 8/8/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_DOMAIN_H
#define FUZZY_INFERENCE_SYSTEM_DOMAIN_H

#include "DomainElement.h"

class Domain {
public:
	virtual DomainElement getElementAt(int index) = 0;
	virtual int getSize() = 0;
};

#endif //FUZZY_INFERENCE_SYSTEM_DOMAIN_H
