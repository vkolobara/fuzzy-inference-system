//
// Created by vkolobara on 16.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_DOMAINRANGE_H
#define FUZZY_INFERENCE_SYSTEM_DOMAINRANGE_H

#include "Domain.h"

class DomainRange : public Domain {
private:
    double start, step, end;
public:
    DomainRange(double start, double step, double end);
    DomainElement getElementAt(int index);
    int getCardinality();
    int getNumberOfComponents();
    shared_ptr<Domain> getComponent(int index);
    int indexOfElement (DomainElement element);
};


#endif //FUZZY_INFERENCE_SYSTEM_DOMAINRANGE_H
