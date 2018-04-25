//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "InferenceSystem.h"

void InferenceSystem::addRule(Rule *rule) {
    rules.push_back(rule);
}

Rule *InferenceSystem::getRule(size_t index) {
    if (index < 0 || index >= rules.size())
        return nullptr;
    return rules.at(index);
}

InferenceSystem::InferenceSystem(BaseOperator::SNorm *snorm) : snorm(snorm) {}

double InferenceSystem::getConclusion(Defuzzifier *defuzzifier) {
    vector<Clause*> clauses;

    for (auto rule : rules) {
        auto newTerm = new ActivationLanguageTerm(rule->consequent->languageTerm->name, rule->antecedent->getActivation(), rule->consequent->languageTerm->clone());
        auto newClause = new Clause(rule->consequent->languageVariable->clone(), newTerm);

        clauses.push_back(newClause);
    }

    double val = defuzzifier->defuzzify(clauses);
    for (auto clause : clauses) {
        delete clause;
    }

    return val;
}

InferenceSystem::~InferenceSystem() {
    delete snorm;

    for (auto var : variables) {
        delete var;
    }

    rules.clear();
}

InferenceSystem *InferenceSystem::clone() const {
    auto newSystem = new InferenceSystem(this->snorm->clone());

    for (auto rule : rules) {
        newSystem->addRule(rule->clone());
    }

    return newSystem;
}

void InferenceSystem::addVariable(LanguageVariable *variable) {
    this->variables.push_back(variable);

}

LanguageVariable *InferenceSystem::getVariable(size_t index) {
    if (index < 0 || index >= this->variables.size()) {
        return nullptr;
    }
    return this->variables.at(index);
}
