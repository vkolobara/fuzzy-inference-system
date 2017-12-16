//
// Created by vkolobara on 12.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_CLAUSE_H
#define FUZZY_INFERENCE_SYSTEM_CLAUSE_H


#include "../language_variable/LanguageVariable.h"
#include "FuzzyInput.h"
#include "../Operators.h"

class Clause {
protected:
    shared_ptr<FuzzySet> fuzzySet;
public:
    virtual double calculateMembership(FuzzyInput fuzzyInput) = 0;
    shared_ptr<FuzzySet> getFuzzySet() {
            return fuzzySet;
    };
};

class SimpleClause : public Clause {
protected:
    shared_ptr<LanguageTerm> languageTerm;
    shared_ptr<LanguageVariable> languageVariable;
public:
    SimpleClause(shared_ptr<LanguageTerm> languageTerm, shared_ptr<LanguageVariable> languageVariable) : languageTerm(languageTerm), languageVariable(languageVariable){
        fuzzySet = languageTerm->getMeaning();
    };
    double calculateMembership(FuzzyInput fuzzyInput);
    shared_ptr<FuzzySet> getFuzzySet();
};

class NotClause : public Clause {
protected:
    shared_ptr<Clause> clause;
    shared_ptr<BaseOperator::Complement> complement;
public:
    NotClause(shared_ptr<Clause> clause);
    double calculateMembership(FuzzyInput fuzzyInput);
    shared_ptr<FuzzySet> getFuzzySet();
};

class OrClause : public Clause {
protected:
    std::vector<shared_ptr<Clause>> clauses;
    shared_ptr<BaseOperator::SNorm> snorm;
public:
    OrClause(std::vector<shared_ptr<Clause>> clauses);
    double calculateMembership(FuzzyInput fuzzyInput);
    shared_ptr<FuzzySet> getFuzzySet();
};

class AndClause : public Clause {
protected:
    std::vector<shared_ptr<Clause>> clauses;
    shared_ptr<BaseOperator::TNorm> tnorm;
public:
    AndClause(std::vector<shared_ptr<Clause>> clauses);
    double calculateMembership(FuzzyInput fuzzyInput);
    shared_ptr<FuzzySet> getFuzzySet();
};
#endif //FUZZY_INFERENCE_SYSTEM_CLAUSE_H
