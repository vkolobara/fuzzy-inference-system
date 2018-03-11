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
    vector<RangeDomain*> domains;
public:
    CompositeDomain(initializer_list<RangeDomain*> domains);

    unsigned int getCardinality() override;

    unsigned int getNumberOfComponents() override;

    Domain* getComponent(unsigned int index) override;
};


#endif //FUZZY_INFERENCE_SYSTEM_COMPOSITEDOMAIN_H
