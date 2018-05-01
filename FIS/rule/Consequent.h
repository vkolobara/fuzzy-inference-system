//
// Created by vkolobara on 5/1/18.
//

#ifndef FUZZY_TIME_SERIES_CONSEQUENT_H
#define FUZZY_TIME_SERIES_CONSEQUENT_H


#include "Clause.h"

class Consequent {
public:
    virtual double membership() = 0;
};

struct FuzzyConsequent : public Consequent{
    shared_ptr<Clause> clause;

    explicit FuzzyConsequent(Clause& clause);

    double membership() override;
};

struct LinearConsequent : public Consequent {

    vector<double> w;
    vector<shared_ptr<LanguageVariable>> variables;

    LinearConsequent(const vector<double> &w, const vector<shared_ptr<LanguageVariable>> &variables);

    double membership() override;
};

#endif //FUZZY_TIME_SERIES_CONSEQUENT_H
