#include "Domain.h"
#include <stdexcept>


DomainRange::DomainRange(double start, double step, double end) : start(start), step(step), end(end) {}

DomainElement DomainRange::getElementAt(int index) {
    if (index > getSize()) {
        throw std::invalid_argument("Index greater than size of domain");
    }
    return DomainElement({start + index * step});
}

int DomainRange::getSize() {
    return (end - start) / step;
}
