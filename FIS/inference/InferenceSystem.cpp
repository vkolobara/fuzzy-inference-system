//
// Created by vkolobara on 12.12.2017..
//

#include <iostream>
#include <utility>
#include "InferenceSystem.h"

MamdaniInferenceSystem::MamdaniInferenceSystem(vector<Rule> rules,
                                               BaseOperator::SNorm* snorm,
                                               Defuzzifier* defuzzifier) : rules(std::move(rules)), snorm(snorm),
                                                                                             defuzzifier(defuzzifier) {}

double MamdaniInferenceSystem::getConclusion(FuzzyInput* fuzzyInput) {

    auto firstConclusion = rules[0].getConclusion(fuzzyInput);

    auto c = firstConclusion;

    for (int i = 1; i < rules.size(); i++) {
        auto conclusion = rules[i].getConclusion(fuzzyInput);
        c = FuzzySet::combine(c, conclusion, snorm);
        delete conclusion;
    }

    delete firstConclusion;
    auto val = defuzzifier->defuzzify(c);

    return val;
}

const vector<Rule> &MamdaniInferenceSystem::getRules() const {
    return rules;
}

MamdaniInferenceSystem::~MamdaniInferenceSystem() {
    delete snorm;
    delete defuzzifier;
}
