//
// Created by vkolobara on 16.12.2017..
//

#include "RangeDomain.h"

RangeDomain::RangeDomain(double start, double step, double end) : start(start), step(step), end(end) {}

unsigned int RangeDomain::getCardinality() {
    return static_cast<unsigned int>((end - start) / step);
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

double RangeDomain::getElementAt(unsigned int index) {
    if (index < 0 || index > getCardinality()) {
        //TODO: ERROR
    }

    return start + (index * step);
}

int RangeDomain::indexOfElement(double element) {
    auto index = (int) ((element - start) / step);

    if (index < 0) index = 0;
    else if (index > end) index = getCardinality()-1;

    return index;
}
