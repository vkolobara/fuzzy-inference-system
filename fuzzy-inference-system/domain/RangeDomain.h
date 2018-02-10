//
// Created by vkolobara on 16.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_DOMAINRANGE_H
#define FUZZY_INFERENCE_SYSTEM_DOMAINRANGE_H

#include "Domain.h"

class RangeDomain : public Domain {
private:
    double start, step, end;
public:
    RangeDomain(double start, double step, double end);

    uint getCardinality() override;

    uint getNumberOfComponents() override;

    Domain* getComponent(uint index) override;

    double getStart() const;

    double getStep() const;

    double getEnd() const;
};


#endif //FUZZY_INFERENCE_SYSTEM_DOMAINRANGE_H
