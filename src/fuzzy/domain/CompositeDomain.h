//
// Created by vkolobara on 16.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_COMPOSITEDOMAIN_H
#define FUZZY_INFERENCE_SYSTEM_COMPOSITEDOMAIN_H

#include "Domain.h"
#include "DomainRange.h"
#include <initializer_list>
#include <vector>

using namespace std;

class CompositeDomain : public Domain {
protected:
    vector<shared_ptr<DomainRange>> domains;
public:
    CompositeDomain(initializer_list<DomainRange> domains);
    int getCardinality();
    int getNumberOfComponents();
    shared_ptr<Domain> getComponent(int index);
    DomainElement getElementAt(int index);
    int indexOfElement (DomainElement element);
};


#endif //FUZZY_INFERENCE_SYSTEM_COMPOSITEDOMAIN_H
