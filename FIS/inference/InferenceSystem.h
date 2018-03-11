//
// Created by vkolobara on 12.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_INFERENCESYSTEM_H
#define FUZZY_INFERENCE_SYSTEM_INFERENCESYSTEM_H

#include "FuzzyInput.h"
#include "Rule.h"
#include "Defuzzifier.h"

class InferenceSystem {
public:
    virtual double getConclusion(FuzzyInput* fuzzyInput) = 0;
};

class MamdaniInferenceSystem : public InferenceSystem {
private:
    vector<Rule> rules;
    BaseOperator::SNorm* snorm;
    Defuzzifier* defuzzifier;
public:
    MamdaniInferenceSystem(vector<Rule> rules, BaseOperator::SNorm* snorm,
                           Defuzzifier* defuzzifier);

    ~MamdaniInferenceSystem();
    
    double getConclusion(FuzzyInput* fuzzyInput) override;

    const vector<Rule> &getRules() const;
};


#endif //FUZZY_INFERENCE_SYSTEM_INFERENCESYSTEM_H
