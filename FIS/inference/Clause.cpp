//
// Created by vkolobara on 12.12.2017..
//

#include "Clause.h"

double SimpleClause::calculateMembership(FuzzyInput fuzzyInput) {
    auto el = fuzzyInput.getValue(languageVariable->getName());
    return languageTerm->getMeaning()->getValueAt(el);
}

NotClause::NotClause(Clause* clause) : NotClause::NotClause(clause, new Zadeh::Complement()) {};

double NotClause::calculateMembership(FuzzyInput fuzzyInput) {
    return this->complement->calculateValue(this->clause->calculateMembership(fuzzyInput));
}

NotClause::NotClause(Clause* clause, BaseOperator::Complement* complement) : clause(
        clause), complement(complement) {}

NotClause::~NotClause() {
    delete clause;
    delete complement;
}

OrClause::OrClause(std::vector<Clause*> clauses) : OrClause::OrClause(clauses,
                                                                                 new Zadeh::SNorm()) {};

double OrClause::calculateMembership(FuzzyInput fuzzyInput) {
    auto val = 0.0;

    for (auto clause : clauses) {
        val = this->snorm->calculateValue(val, clause->calculateMembership(fuzzyInput));
    }

    return val;
}

OrClause::OrClause(const vector<Clause*> clauses, BaseOperator::SNorm* snorm) : clauses(
        clauses), snorm(snorm) {}

OrClause::~OrClause() {
    delete snorm;
    for (auto clause : clauses) {
        delete clause;
    }
    clauses.clear();

}

AndClause::AndClause(std::vector<Clause*> clauses) : AndClause::AndClause(clauses,
                                                                                     new Zadeh::TNorm()) {};

double AndClause::calculateMembership(FuzzyInput fuzzyInput) {
    auto val = 1.0;

    for (auto clause : clauses) {
        val = this->tnorm->calculateValue(val, clause->calculateMembership(fuzzyInput));
    }

    return val;
}

AndClause::AndClause(vector<Clause*> clauses, BaseOperator::TNorm* tnorm) : clauses(
        clauses), tnorm(tnorm) {}

AndClause::~AndClause() {
    delete tnorm;

    for (auto clause : clauses) {
        delete clause;
    }

    clauses.clear();

}
