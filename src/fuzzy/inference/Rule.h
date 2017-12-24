//
// Created by vkolobara on 16.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_RULE_H
#define FUZZY_INFERENCE_SYSTEM_RULE_H


#include <utility>

#include "../FuzzySet.h"
#include "Clause.h"

class Rule {
protected:
    shared_ptr<Clause> antecedent;
    shared_ptr<FuzzySet> consequense;
    shared_ptr<BaseOperator::TNorm> tnorm;
public:
    Rule(shared_ptr<Clause> antecedent, shared_ptr<FuzzySet> consequense,
         shared_ptr<BaseOperator::TNorm> tnorm) : antecedent(std::move(antecedent)), consequense(
            std::move(consequense)), tnorm(std::move(tnorm)) {};


    unique_ptr<FuzzySet> getConclusion();
};


#endif //FUZZY_INFERENCE_SYSTEM_RULE_H
