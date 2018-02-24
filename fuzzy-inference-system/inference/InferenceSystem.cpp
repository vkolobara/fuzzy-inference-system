//
// Created by vkolobara on 12.12.2017..
//

#include <iostream>
#include "InferenceSystem.h"

MamdaniInferenceSystem::MamdaniInferenceSystem(vector<Rule*> rules,
                                               BaseOperator::SNorm* snorm,
                                               Defuzzifier* defuzzifier) : rules(rules), snorm(snorm),
                                                                                             defuzzifier(defuzzifier) {}

double MamdaniInferenceSystem::getConclusion(FuzzyInput* fuzzyInput) {

    auto c = rules[0]->getConclusion(fuzzyInput);

    for (int i = 1; i < rules.size(); i++) {
        c = FuzzySet::combine(c, rules[i]->getConclusion(fuzzyInput), snorm);
    }

    for (unsigned int i = 0; i < c->getDomain()->getCardinality(); i++) {
        DomainElement el = c->getDomain()->getElementAt(i);
    }

    return defuzzifier->defuzzify(c);
}

const vector<Rule*> &MamdaniInferenceSystem::getRules() const {
    return rules;
}

MamdaniInferenceSystem::~MamdaniInferenceSystem() {
    delete defuzzifier;
    delete snorm;

    for (auto rule : rules) delete rule;
    rules.clear();
}
