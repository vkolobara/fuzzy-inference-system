//
// Created by vkolobara on 8/8/17.
//

#ifndef DIPLOMSKI_DOMAIN_H
#define DIPLOMSKI_DOMAIN_H
#include "DomainElement.h"

class Domain {
public:
	virtual DomainElement getElementAt(int index) = 0;
	virtual int getSize() = 0;
};

#endif //DIPLOMSKI_DOMAIN_H
