//
// Created by vkolobara on 12.12.2017..
//

#include "Clause.h"

#include <utility>
#include "../MembershipFunction.h"

double SimpleClause::calculateMembership(FuzzyInput fuzzyInput) {
    auto el = fuzzyInput.getValue(languageVariable->getName());
    return languageTerm->getMeaning()->getValueAt(*el);
}

NotClause::NotClause(shared_ptr<Clause> clause) {
    this->clause = std::move(clause);
    this->complement = shared_ptr<BaseOperator::Complement>(new Zadeh::Complement());
}

double NotClause::calculateMembership(FuzzyInput fuzzyInput) {
    return this->complement->calculateValue(this->clause->calculateMembership(fuzzyInput));
}

OrClause::OrClause(std::vector<shared_ptr<Clause>> clauses) : clauses(clauses) {
    this->snorm = shared_ptr<BaseOperator::SNorm>(new Zadeh::SNorm());
}

double OrClause::calculateMembership(FuzzyInput fuzzyInput) {
    auto val = 0.0;

    for (const shared_ptr<Clause> &clause : clauses) {
        val = this->snorm->calculateValue(val, clause->calculateMembership(fuzzyInput));
    }

    return val;
}

AndClause::AndClause(std::vector<shared_ptr<Clause>> clauses) : clauses(clauses) {
    this->tnorm = shared_ptr<BaseOperator::TNorm>(new Zadeh::TNorm());
}

double AndClause::calculateMembership(FuzzyInput fuzzyInput) {
    auto val = 1.0;

    for (const shared_ptr<Clause> &clause : clauses) {
        val = this->tnorm->calculateValue(val, clause->calculateMembership(fuzzyInput));
    }

    return val;
}