//
// Created by vkolobara on 12.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_CLAUSE_H
#define FUZZY_INFERENCE_SYSTEM_CLAUSE_H


#include <utility>

#include "../language_variable/LanguageVariable.h"
#include "FuzzyInput.h"
#include "../fuzzyset/Operators.h"
#include "../fuzzyset/FuzzySet.h"

class Clause {
public:
    virtual double calculateMembership(FuzzyInput fuzzyInput) = 0;
};

class SimpleClause : public Clause {
protected:
    shared_ptr<LanguageTerm> languageTerm;
    shared_ptr<LanguageVariable> languageVariable;
public:
    SimpleClause(shared_ptr<LanguageTerm> languageTerm, shared_ptr<LanguageVariable> languageVariable) :
            languageTerm(languageTerm), languageVariable(languageVariable) {
    };

    double calculateMembership(FuzzyInput fuzzyInput) override;
};

class NotClause : public Clause {
protected:
    shared_ptr<Clause> clause;
    shared_ptr<BaseOperator::Complement> complement;
public:
    NotClause(shared_ptr<Clause> clause, shared_ptr<BaseOperator::Complement> complement);

    explicit NotClause(shared_ptr<Clause> clause);

    double calculateMembership(FuzzyInput fuzzyInput) override;
};

class OrClause : public Clause {
protected:
    std::vector<shared_ptr<Clause>> clauses;
    shared_ptr<BaseOperator::SNorm> snorm;
public:
    explicit OrClause(std::vector<shared_ptr<Clause>> clauses);

    OrClause(vector<shared_ptr<Clause>> clauses, shared_ptr<BaseOperator::SNorm> snorm);

    double calculateMembership(FuzzyInput fuzzyInput) override;
};

class AndClause : public Clause {
protected:
    std::vector<shared_ptr<Clause>> clauses;
    shared_ptr<BaseOperator::TNorm> tnorm;
public:
    explicit AndClause(std::vector<shared_ptr<Clause>> clauses);

    AndClause(vector<shared_ptr<Clause>> clauses, shared_ptr<BaseOperator::TNorm> tnorm);

    double calculateMembership(FuzzyInput fuzzyInput) override;
};

#endif //FUZZY_INFERENCE_SYSTEM_CLAUSE_H
