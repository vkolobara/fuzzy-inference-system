//
// Created by vkolobara on 16.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_COMPOSITEDOMAIN_H
#define FUZZY_INFERENCE_SYSTEM_COMPOSITEDOMAIN_H

#include "Domain.h"
#include "RangeDomain.h"
#include <initializer_list>
#include <vector>

using namespace std;

class CompositeDomain : public Domain {
protected:
    vector<shared_ptr<RangeDomain>> domains;
public:
    CompositeDomain(initializer_list<shared_ptr<RangeDomain>> domains);
    uint getCardinality() override;
    unsigned long getNumberOfComponents() override;
    shared_ptr<Domain> getComponent(uint index) override;
    DomainElement getElementAt(uint index) override;
    uint indexOfElement (DomainElement element) override;
};


#endif //FUZZY_INFERENCE_SYSTEM_COMPOSITEDOMAIN_H
