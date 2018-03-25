//
// Created by vkolobara on 12/26/17.
//

#include "Defuzzifier.h"


double COADefuzzifier::defuzzify(FuzzySet* fuzzySet) {
    double sum = 0;
    double sumX = 0;

    auto domain = fuzzySet->getDomain();

    for (unsigned int i = 0; i < domain->getCardinality(); i++) {
        auto el = domain->getElementAt(i);

        sumX += fuzzySet->getValueAt(el) * el;
        sum += fuzzySet->getValueAt(el);
    }

    if (sum == 0) return 0;

    return sumX / sum;
}
