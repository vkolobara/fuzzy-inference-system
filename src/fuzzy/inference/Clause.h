//
// Created by vkolobara on 12.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_CLAUSE_H
#define FUZZY_INFERENCE_SYSTEM_CLAUSE_H


#include "../language_variable/LanguageVariable.h"
#include "FuzzyInput.h"

class Clause {
public:
    virtual double calculateMembership(FuzzyInput fuzzyInput) = 0;
};

class SimpleClause : public Clause {
protected:
    LanguageTerm languageTerm;
    LanguageVariable languageVariable;
public:
    SimpleClause(const LanguageTerm &languageTerm, const LanguageVariable &languageVariable){};
    double calculateMembership(FuzzyInput fuzzyInput) {};
};

class NotClause : public Clause {
protected:
    shared_ptr<Clause> clause;
    shared_ptr<BaseOperator::Complement> complement;    
public:
    NotClause(shared_ptr<Clause> clause) {};
    double calculateMembership(FuzzyInput fuzzyInput) {}; 
};

class OrClause : public Clause {
protected:
    std::vector<shared_ptr<Clause>> clauses;
    shared_ptr<BaseOperator::SNorm> snorm;
public:
    OrClause(std::initializer_list<shared_ptr<Clause>> clauses) {};
    double calculateMembership(FuzzyInput fuzzyInput) {};
};

class AndClause : public Clause {
protected:
    std::vector<shared_ptr<Clause>> clauses;
    shared_ptr<BaseOperator::TNorm> tnorm;
public:
    OrClause(std::initializer_list<shared_ptr<Clause>> clauses) {};
    double calculateMembership(FuzzyInput fuzzyInput) {};
};
#endif //FUZZY_INFERENCE_SYSTEM_CLAUSE_H
