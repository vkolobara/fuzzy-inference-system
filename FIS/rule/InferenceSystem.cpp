//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "InferenceSystem.h"

#include <utility>

void InferenceSystem::addRule(Rule& rule) {
    rules.push_back(shared_ptr<Rule>(&rule));
}

Rule* InferenceSystem::getRule(size_t index) {
    if (index < 0 || index >= rules.size())
        return nullptr;
    return rules.at(index).get();
}

InferenceSystem::InferenceSystem(shared_ptr<KnowledgeBase> knowledgeBase) : knowledgeBase(std::move(knowledgeBase)) {}

double TSKInferenceSystem::getConclusion() {
    double sumX = 0;
    double sum = 0;

    for (const auto &rule : rules) {
        double activation = rule->antecedent.get()->getActivation();
        double val = rule->consequent->membership();

        sumX += activation * val;
        sum += activation;
    }

    if (sum <= 1e-6) sum = 1;
    return sumX / sum;
}

TSKInferenceSystem::TSKInferenceSystem(shared_ptr<KnowledgeBase> knowledgeBase) : InferenceSystem(
        knowledgeBase) {}
