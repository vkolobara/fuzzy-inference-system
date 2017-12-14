//
// Created by vkolobara on 12.12.2017..
//

#include "Clause.h"
#include "../Operators.cpp"
#include <initializer_list>
#include <vector>

class SimpleClause : public Clause {
private:
    LanguageTerm languageTerm;
    LanguageVariable languageVariable;
public:
    SimpleClause(const LanguageTerm &languageTerm, const LanguageVariable &languageVariable) : languageTerm(
            languageTerm), languageVariable(languageVariable) {}

    double calculateMembership(FuzzyInput fuzzyInput) {
        return languageTerm.getMeaning()->valueAt(fuzzyInput.getValue(languageVariable.getName()));
    }
};

class NotClause : public Clause {
private:
    shared_ptr<Clause> clause;
    shared_ptr<BaseOperator::Complement> complement;
public:
    NotClause(shared_ptr<Clause> clause) {
        this->clause = clause;
        this->complement = shared_ptr<BaseOperator::Complement>(new Zadeh::Complement());
    }

    double calculateMembership(FuzzyInput fuzzyInput) {
        return complement->calculateValue(clause->calculateMembership(fuzzyInput));
    }
};

class OrClause : public Clause {
private:
    std::vector<shared_ptr<Clause>> clauses;
    shared_ptr<BaseOperator::SNorm> snorm;
public:
    OrClause(std::initializer_list<shared_ptr<Clause>> clauses) {
    	this->clauses = std::vector<shared_ptr<Clause>>(clauses);
	this->snorm = shared_ptr<BaseOperator::SNorm>(new Zadeh::SNorm());
    }


}
