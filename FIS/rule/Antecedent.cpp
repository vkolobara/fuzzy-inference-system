//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "Antecedent.h"

Antecedent::Antecedent(BaseOperator::TNorm& tnorm) {
    make_unique<BaseOperator::TNorm>(tnorm);
}

void Antecedent::addClause(Clause& clause) {
    clauses.push_back(make_shared<Clause>(clause));
}

weak_ptr<Clause> Antecedent::getClause(size_t index) {
    if (index < 0 || index >= clauses.size())
        return nullptr;

    return clauses.at(index);
}

double Antecedent::getActivation() {
    double value = 1;

    for (auto clause : clauses) {
        value = tnorm->calculateValue(value, clause->membership());
    }

    return value;
}
