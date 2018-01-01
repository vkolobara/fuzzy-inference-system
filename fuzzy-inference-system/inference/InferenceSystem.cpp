//
// Created by vkolobara on 12.12.2017..
//

#include <iostream>
#include "InferenceSystem.h"

MamdaniInferenceSystem::MamdaniInferenceSystem(const vector<shared_ptr<Rule>> &rules,
                                               const shared_ptr<BaseOperator::SNorm> &snorm,
                                               const shared_ptr<Defuzzifier> &defuzzifier) : rules(rules), snorm(snorm),
                                                                                             defuzzifier(defuzzifier) {}

double MamdaniInferenceSystem::getConclusion(shared_ptr<FuzzyInput> fuzzyInput) {

    shared_ptr<FuzzySet> c = rules[0]->getConclusion(fuzzyInput);

    for (int i = 1; i < rules.size(); i++) {
        c = FuzzySet::combine(c, rules[i]->getConclusion(fuzzyInput), snorm);
    }

    for (uint i = 0; i < c->getDomain()->getCardinality(); i++) {
        DomainElement el = c->getDomain()->getElementAt(i);

        cout << el.getComponentValue(0) << " " << c->getValueAt(el) << endl;
    }
    cout << endl;

    return defuzzifier->defuzzify(c);
}

const vector<shared_ptr<Rule>> &MamdaniInferenceSystem::getRules() const {
    return rules;
}
