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

struct LinearVariableConsequent : public Consequent {

    vector<double> w;
    vector<shared_ptr<LanguageVariable>> variables;

    LinearVariableConsequent(const vector<double> &w, const vector<shared_ptr<LanguageVariable>> &variables);

    double membership() override;
};

struct LinearClauseConsequent : public Consequent {
    vector<double> w;
    vector<shared_ptr<Clause>> clauses;

    LinearClauseConsequent(const vector<double> &w, const vector<shared_ptr<Clause>> &clauses);

    double membership() override;
};

struct ConstantConsequent : public Consequent {
    double value;

    ConstantConsequent(double value);

    double membership() override;
};

struct MultipleConstantConsequent : public Consequent {
    vector<double> values;
    vector<double> weights;

    MultipleConstantConsequent(const vector<double> &values, const vector<double> &weights);

    double membership() override;

};

#endif //FUZZY_TIME_SERIES_CONSEQUENT_H
