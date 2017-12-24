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
    DomainElement getElementAt(uint index) override;
    uint getCardinality() override;
    uint getNumberOfComponents() override;
    shared_ptr<Domain> getComponent(uint index) override;
    uint indexOfElement (DomainElement element) override;
};


#endif //FUZZY_INFERENCE_SYSTEM_DOMAINRANGE_H
