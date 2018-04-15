//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#ifndef FUZZY_TIME_SERIES_INFERENCESYSTEM_H
#define FUZZY_TIME_SERIES_INFERENCESYSTEM_H


#include <vector>
#include "Rule.h"
#include "Defuzzifier.h"

struct InferenceSystem {
    BaseOperator::SNorm* snorm;

    std::vector<Rule*> rules;
    std::vector<LanguageVariable*> variables;

    explicit InferenceSystem(BaseOperator::SNorm *snorm);
    ~InferenceSystem();

    InferenceSystem* clone() const;

    void addRule(Rule* rule);
    Rule* getRule(size_t index);

    void addVariable(LanguageVariable* variable);
    LanguageVariable* getVariable(size_t index);

    double getConclusion(Defuzzifier* defuzzifier);

};


#endif //FUZZY_TIME_SERIES_INFERENCESYSTEM_H
