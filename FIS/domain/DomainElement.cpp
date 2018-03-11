#include "DomainElement.h"

#include <utility>

DomainElement::DomainElement(std::initializer_list<double> valuesList) {
    values = std::vector<double>(valuesList);
}

double DomainElement::getComponentValue(unsigned int index) {
    //TODO: ERROR IF INDEX OUT OF RANGE
    return values[index];
}

DomainElement::DomainElement(std::vector<double> values) : values(std::move(values)) {}

double DomainElement::getNumberOfComponents() {
    return values.size();
}
