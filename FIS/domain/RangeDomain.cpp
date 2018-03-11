//
// Created by vkolobara on 16.12.2017..
//

#include "RangeDomain.h"

RangeDomain::RangeDomain(double start, double step, double end) : start(start), step(step), end(end) {}

unsigned int RangeDomain::getCardinality() {
    return static_cast<unsigned int>((end - start) / step);
}

Domain* RangeDomain::getComponent(unsigned int index) {
    return this;
}


unsigned int RangeDomain::getNumberOfComponents() {
    return 1;
}

double RangeDomain::getStart() const {
    return start;
}

double RangeDomain::getStep() const {
    return step;
}

double RangeDomain::getEnd() const {
    return end;
}
