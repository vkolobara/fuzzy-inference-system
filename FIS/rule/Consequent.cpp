//
// Created by vkolobara on 5/1/18.
//

#include "Consequent.h"

FuzzyConsequent::FuzzyConsequent(Clause& clause) {
    this->clause = shared_ptr<Clause>(&clause);
}

double FuzzyConsequent::membership() {
    return clause->membership();
}

double LinearVariableConsequent::membership() {
    double value = 0;

    for (auto i = 0; i<variables.size(); i++) {
        value += w.at(i) * variables.at(i)->value;
    }
    return value;
}

LinearVariableConsequent::LinearVariableConsequent(const vector<double> &w, const vector<shared_ptr<LanguageVariable>> &variables) : w(
        w), variables(variables) {}

double ConstantConsequent::membership() {
    return value;
}

ConstantConsequent::ConstantConsequent(double value) : value(value) {}

LinearClauseConsequent::LinearClauseConsequent(const vector<double> &w, const vector<shared_ptr<Clause>> &clauses) : w(
        w), clauses(clauses) {}

double LinearClauseConsequent::membership() {
    double val = 0;

    for (auto i=0; i<w.size(); i++) {
        auto termIndex = clauses.at(i)->termIndex;
        val += w.at(i) * clauses.at(i)->languageVariable->terms[termIndex]->midpoint();
    }

    return val;
}
