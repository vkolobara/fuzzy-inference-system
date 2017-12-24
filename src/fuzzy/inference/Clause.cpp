//
// Created by vkolobara on 12.12.2017..
//

#include "Clause.h"

#include <utility>
#include "../FuzzySet.h"

double SimpleClause::calculateMembership(FuzzyInput fuzzyInput) {
    return languageTerm->getMeaning()->valueAt(fuzzyInput.getValue(languageVariable->getName()));
}

NotClause::NotClause(shared_ptr<Clause> clause) {
    this->clause = std::move(clause);
    this->complement = shared_ptr<BaseOperator::Complement>(new Zadeh::Complement());
    this->fuzzySet = shared_ptr<FuzzySet>(new NotFuzzySet(this->clause->getFuzzySet(), this->complement));
}

double NotClause::calculateMembership(FuzzyInput fuzzyInput) {
    return this->complement->calculateValue(this->clause->calculateMembership(fuzzyInput));
}

OrClause::OrClause(std::vector<shared_ptr<Clause>> clauses) : clauses(clauses) {
    this->snorm = shared_ptr<BaseOperator::SNorm>(new Zadeh::SNorm());

    auto size = clauses.size();

    vector<shared_ptr<FuzzySet>> fuzzySets = vector<shared_ptr<FuzzySet>>(size);

    for (int i=0; i<size; i++) {
        fuzzySets[i] = this->clauses[i]->getFuzzySet();
    }

    this->fuzzySet = std::make_shared<OrFuzzySet>(fuzzySets, this->snorm);
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

    auto size = clauses.size();

    vector<shared_ptr<FuzzySet>> fuzzySets = vector<shared_ptr<FuzzySet>>(size);

    for (int i=0; i<size; i++) {
        fuzzySets[i] = this->clauses[i]->getFuzzySet();
    }

    this->fuzzySet = std::make_shared<AndFuzzySet>(fuzzySets, this->tnorm);
}

double AndClause::calculateMembership(FuzzyInput fuzzyInput) {
    auto val = 1.0;

    for (const shared_ptr<Clause> &clause : clauses) {
        val = this->tnorm->calculateValue(val, clause->calculateMembership(fuzzyInput));
    }

    return val;
}