#ifndef FUZZY_INFERENCE_SYSTEM_DOMAINELEMENT_H
#define FUZZY_INFERENCE_SYSTEM_DOMAINELEMENT_H


#include <initializer_list>
#include <vector>
#include <zconf.h>

class DomainElement {
protected:
    std::vector<double> values;
public:
    DomainElement(std::initializer_list<double> values);

    explicit DomainElement(std::vector<double> values);

    double getComponentValue(unsigned int index);

    double getNumberOfComponents();
};

#endif //FUZZY_INFERENCE_SYSTEM_DOMAINELEMENT_H
