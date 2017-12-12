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

class DomainRange : Domain {
private:
    double start, step, end;
public:
    DomainRange(double start, double step, double end);
    DomainElement getElementAt(int index);
    int getSize();
};
#endif //FUZZY_INFERENCE_SYSTEM_DOMAIN_H
