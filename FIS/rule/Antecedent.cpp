//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "Antecedent.h"

Antecedent::Antecedent(BaseOperator::TNorm *tnorm) : tnorm(tnorm) {}

void Antecedent::addClause(Clause *clause) {
    clauses.push_back(clause);
}

Clause *Antecedent::getClause(size_t index) {
    if (index < 0 || index >= clauses.size())
        return nullptr;

    return clauses.at(index);
}

double Antecedent::getActivation() {
    double value = 0;

    for (auto clause : clauses) {
        value = tnorm->calculateValue(value, clause->membership());
    }

    return value;
}

Antecedent::~Antecedent() {
    delete tnorm;

    for (auto clause : clauses) {
        delete clause;
    }

    clauses.clear();

}

Antecedent *Antecedent::clone() const {
    auto newAntecedent = new Antecedent(this->tnorm->clone());

    for (auto clause : clauses) {
        newAntecedent->addClause(clause->clone());
    }

    return newAntecedent;
}
