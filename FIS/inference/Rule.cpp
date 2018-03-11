//
// Created by vkolobara on 16.12.2017..
//

#include <iostream>
#include "Rule.h"

FuzzySet* Rule::getConclusion(FuzzyInput* fuzzyInput) {

    auto ret = new MutableFuzzySet(consequense->getDomain());

    for (unsigned int i = 0; i < ret->getDomain()->getCardinality(); i++) {
        DomainElement el = ret->getDomain()->getElementAt(i);

        ret->set(el, tnorm->calculateValue(antecedent->calculateMembership(*fuzzyInput), consequense->getValueAt(el)));

    }

    return ret;
}
