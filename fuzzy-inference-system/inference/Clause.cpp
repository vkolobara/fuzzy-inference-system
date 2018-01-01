//
// Created by vkolobara on 12.12.2017..
//

#include "Clause.h"

double SimpleClause::calculateMembership(FuzzyInput fuzzyInput) {
    auto el = fuzzyInput.getValue(languageVariable->getName());
    return languageTerm->getMeaning()->getValueAt(*el);
}

NotClause::NotClause(shared_ptr<Clause> clause) : NotClause::NotClause(clause, make_shared<Zadeh::Complement>()) {};

double NotClause::calculateMembership(FuzzyInput fuzzyInput) {
    return this->complement->calculateValue(this->clause->calculateMembership(fuzzyInput));
}

NotClause::NotClause(const shared_ptr<Clause> &clause, const shared_ptr<BaseOperator::Complement> &complement) : clause(
        clause), complement(complement) {}

OrClause::OrClause(std::vector<shared_ptr<Clause>> clauses) : OrClause::OrClause(clauses,
                                                                                 make_shared<Zadeh::SNorm>()) {};

double OrClause::calculateMembership(FuzzyInput fuzzyInput) {
    auto val = 0.0;

    for (const shared_ptr<Clause> &clause : clauses) {
        val = this->snorm->calculateValue(val, clause->calculateMembership(fuzzyInput));
    }

    return val;
}

OrClause::OrClause(const vector<shared_ptr<Clause>> &clauses, const shared_ptr<BaseOperator::SNorm> &snorm) : clauses(
        clauses), snorm(snorm) {}

AndClause::AndClause(std::vector<shared_ptr<Clause>> clauses) : AndClause::AndClause(clauses,
                                                                                     make_shared<Zadeh::TNorm>()) {};

double AndClause::calculateMembership(FuzzyInput fuzzyInput) {
    auto val = 1.0;

    for (const shared_ptr<Clause> &clause : clauses) {
        val = this->tnorm->calculateValue(val, clause->calculateMembership(fuzzyInput));
    }

    return val;
}

AndClause::AndClause(const vector<shared_ptr<Clause>> &clauses, const shared_ptr<BaseOperator::TNorm> &tnorm) : clauses(
        clauses), tnorm(tnorm) {}
