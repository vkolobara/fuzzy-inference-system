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
    virtual double getConclusion(shared_ptr<FuzzyInput> fuzzyInput) = 0;
};

class MamdaniInferenceSystem : public InferenceSystem {
private:
    vector<shared_ptr<Rule>> rules;
    shared_ptr<BaseOperator::SNorm> snorm;
    shared_ptr<Defuzzifier> defuzzifier;
public:
    MamdaniInferenceSystem(vector<shared_ptr<Rule>> rules, shared_ptr<BaseOperator::SNorm> snorm,
                           shared_ptr<Defuzzifier> defuzzifier);

    double getConclusion(shared_ptr<FuzzyInput> fuzzyInput) override;

    const vector<shared_ptr<Rule>> &getRules() const;
};


#endif //FUZZY_INFERENCE_SYSTEM_INFERENCESYSTEM_H
