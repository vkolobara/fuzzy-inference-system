//
// Created by vkolobara on 16.12.2017..
//

#include <iostream>
#include "Rule.h"

shared_ptr<FuzzySet> Rule::getConclusion(shared_ptr<FuzzyInput> fuzzyInput) {

    auto ret = make_shared<MutableFuzzySet>(consequense->getDomain());

    for (uint i = 0; i < ret->getDomain()->getCardinality(); i++) {
        DomainElement el = ret->getDomain()->getElementAt(i);

        ret->set(el, tnorm->calculateValue(antecedent->calculateMembership(*fuzzyInput), consequense->getValueAt(el)));

    }

    return ret;
}
