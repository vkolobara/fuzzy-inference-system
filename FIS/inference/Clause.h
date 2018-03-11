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
    LanguageTerm* languageTerm;
    LanguageVariable* languageVariable;
public:
    SimpleClause(LanguageTerm* languageTerm, LanguageVariable* languageVariable) :
            languageTerm(languageTerm), languageVariable(languageVariable) {
    };

    double calculateMembership(FuzzyInput fuzzyInput) override;
};

class NotClause : public Clause {
protected:
    Clause* clause;
    BaseOperator::Complement* complement;
public:
    NotClause(Clause* clause, BaseOperator::Complement* complement);

    virtual ~NotClause();

    explicit NotClause(Clause* clause);

    double calculateMembership(FuzzyInput fuzzyInput) override;
};

class OrClause : public Clause {
protected:
    std::vector<Clause*> clauses;
    BaseOperator::SNorm* snorm;
public:
    explicit OrClause(std::vector<Clause*> clauses);

    virtual ~OrClause();

    OrClause(vector<Clause*> clauses, BaseOperator::SNorm* snorm);

    double calculateMembership(FuzzyInput fuzzyInput) override;
};

class AndClause : public Clause {
protected:
    std::vector<Clause*> clauses;
    BaseOperator::TNorm* tnorm;
public:
    explicit AndClause(std::vector<Clause*> clauses);

    virtual ~AndClause();

    AndClause(vector<Clause*> clauses, BaseOperator::TNorm* tnorm);

    double calculateMembership(FuzzyInput fuzzyInput) override;
};

#endif //FUZZY_INFERENCE_SYSTEM_CLAUSE_H
