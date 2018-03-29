//
// Created by vkolobara on 12.12.2017..
//

#include <iostream>
#include <utility>
#include "InferenceSystem.h"

MamdaniInferenceSystem::MamdaniInferenceSystem(vector<shared_ptr<Rule>> rules,
                                               shared_ptr<BaseOperator::SNorm> snorm,
                                               shared_ptr<Defuzzifier> defuzzifier) : rules(std::move(rules)), snorm(snorm),
                                                                                             defuzzifier(defuzzifier) {}

double MamdaniInferenceSystem::getConclusion(shared_ptr<FuzzyInput> fuzzyInput) {

    auto c = rules[0]->getConclusion(fuzzyInput);

    for (int i = 1; i < rules.size(); i++) {
        auto conclusion = rules[i]->getConclusion(fuzzyInput);
        c = FuzzySet::combine(c, conclusion, snorm);
    }

    auto val = defuzzifier->defuzzify(c);

    return val;
}

const vector<shared_ptr<Rule>> &MamdaniInferenceSystem::getRules() const {
    return rules;
}
