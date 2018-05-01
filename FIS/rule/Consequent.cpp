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

double LinearConsequent::membership() {
    double value = w.at(0);
    for (auto i = 0; i<variables.size(); i++) {
        value += w.at(i+1) * variables.at(i)->value;
    }
    return value;
}

LinearConsequent::LinearConsequent(const vector<double> &w, const vector<shared_ptr<LanguageVariable>> &variables) : w(
        w), variables(variables) {}
