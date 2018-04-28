//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#ifndef FUZZY_TIME_SERIES_INFERENCESYSTEM_H
#define FUZZY_TIME_SERIES_INFERENCESYSTEM_H


#include <vector>
#include "Rule.h"
#include "Defuzzifier.h"

struct InferenceSystem {
    unique_ptr<BaseOperator::SNorm> snorm;

    std::vector<shared_ptr<Rule>> rules;
    std::vector<shared_ptr<LanguageVariable>> variables;

    explicit InferenceSystem(BaseOperator::SNorm& snorm);

    void addRule(Rule& rule);
    weak_ptr<Rule> getRule(size_t index);

    void addVariable(LanguageVariable& variable);
    weak_ptr<LanguageVariable> getVariable(size_t index);

    double getConclusion(Defuzzifier* defuzzifier);

};


#endif //FUZZY_TIME_SERIES_INFERENCESYSTEM_H
