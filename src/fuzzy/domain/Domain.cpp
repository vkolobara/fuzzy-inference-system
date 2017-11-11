#include "Domain.h"
#include <stdexcept>


DomainElement::DomainElement(...) {
}

class DomainRange : public Domain {
private:
	double start, step, end;
public:
	DomainRange(double start, double step, double end) : start(start), step(step), end(end) {}
	DomainElement getElementAt(int index) {
		if (index > getSize()) {
			throw std::invalid_argument("Index greater than size of domain");
		}
		return DomainElement(start + index * step);
	}
	int getSize() {
		return (end - start) / step;
	}
};
