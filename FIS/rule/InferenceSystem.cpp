//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "InferenceSystem.h"

void InferenceSystem::addRule(Rule& rule) {
    rules.push_back(make_shared<Rule>(rule));
}

weak_ptr<Rule> InferenceSystem::getRule(size_t index) {
    if (index < 0 || index >= rules.size())
        return nullptr;
    return rules.at(index);
}

InferenceSystem::InferenceSystem(BaseOperator::SNorm& snorm) {
    this->snorm = make_unique<BaseOperator::SNorm>(snorm);
}

double InferenceSystem::getConclusion(Defuzzifier *defuzzifier) {
    vector<Clause*> clauses;

    for (auto rule : rules) {
        auto newTerm = make_unique<ActivationLanguageTerm>(rule->consequent->languageTerm->name, rule->antecedent->getActivation(), rule->consequent->languageTerm);
        auto newClause = make_unique<Clause>(rule->consequent->languageVariable, newTerm);

        clauses.push_back(newClause.get());
    }

    double val = defuzzifier->defuzzify(clauses);
    
    return val;
}

void InferenceSystem::addVariable(LanguageVariable& variable) {
    this->variables.push_back(make_shared<LanguageVariable>(variable));

}

weak_ptr<LanguageVariable> InferenceSystem::getVariable(size_t index) {
    if (index < 0 || index >= this->variables.size()) {
        return nullptr;
    }
    return this->variables.at(index);
}
