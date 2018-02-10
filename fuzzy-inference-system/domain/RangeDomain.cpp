//
// Created by vkolobara on 16.12.2017..
//

#include "RangeDomain.h"

RangeDomain::RangeDomain(double start, double step, double end) : start(start), step(step), end(end) {}

uint RangeDomain::getCardinality() {
    return static_cast<uint>((end - start) / step);
}

Domain* RangeDomain::getComponent(uint index) {
    return this;
}


uint RangeDomain::getNumberOfComponents() {
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
