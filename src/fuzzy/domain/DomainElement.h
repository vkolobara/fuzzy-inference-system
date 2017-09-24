#ifndef DIPLOMSKI_DOMAINELEMENT_H
#define DIPLOMSKI_DOMAINELEMENT_H

#include <initializer_list>
#include <vector>

class DomainElement{
protected:
	std::vector<double> values;
public:
	DomainElement(std::initializer_list<double> values);
};

#endif //DIPLOMSKI_DOMAINELEMENT_H
