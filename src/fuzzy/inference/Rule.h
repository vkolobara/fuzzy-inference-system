//
// Created by vkolobara on 16.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_RULE_H
#define FUZZY_INFERENCE_SYSTEM_RULE_H


#include <utility>

#include "../MembershipFunction.h"
#include "Clause.h"
#include "../FuzzySet.h"

class Rule {
protected:
    shared_ptr<Clause> antecedent;
    shared_ptr<FuzzySet> consequense;
    shared_ptr<BaseOperator::TNorm> tnorm;
public:
    Rule(shared_ptr<Clause> antecedent, shared_ptr<FuzzySet> consequense,
         shared_ptr<BaseOperator::TNorm> tnorm) : antecedent(std::move(antecedent)), consequense(std::move(
            consequense)), tnorm(std::move(tnorm)) {};


    shared_ptr<FuzzySet> getConclusion(shared_ptr<FuzzyInput> fuzzyInput);
};


#endif //FUZZY_INFERENCE_SYSTEM_RULE_H
