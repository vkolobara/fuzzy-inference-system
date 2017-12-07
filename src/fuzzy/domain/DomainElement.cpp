#include "DomainElement.h"

DomainElement::DomainElement(std::initializer_list<double> valuesList) {
    values = std::vector<double>(valuesList);
}
