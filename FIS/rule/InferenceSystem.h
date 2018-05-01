//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#ifndef FUZZY_TIME_SERIES_INFERENCESYSTEM_H
#define FUZZY_TIME_SERIES_INFERENCESYSTEM_H


#include <vector>
#include "Rule.h"
#include "KnowledgeBase.h"

struct InferenceSystem {

    explicit InferenceSystem(shared_ptr<KnowledgeBase> knowledgeBase);

    shared_ptr<KnowledgeBase> knowledgeBase;
    vector<shared_ptr<Rule>> rules;

    void addRule(Rule& rule);
    Rule* getRule(size_t index);

    virtual double getConclusion() = 0;

};

struct TSKInferenceSystem : public InferenceSystem {
    explicit TSKInferenceSystem(shared_ptr<KnowledgeBase> knowledgeBase);

    double getConclusion() override;
};


#endif //FUZZY_TIME_SERIES_INFERENCESYSTEM_H
