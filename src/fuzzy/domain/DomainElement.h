#ifndef FUZZY_INFERENCE_SYSTEM_DOMAINELEMENT_H
#define FUZZY_INFERENCE_SYSTEM_DOMAINELEMENT_H


#include <initializer_list>
#include <vector>

class DomainElement{
protected:
	std::vector<double> values;
public:
	DomainElement(std::initializer_list<double> values);
};

#endif //FUZZY_INFERENCE_SYSTEM_DOMAINELEMENT_H
