//
// Created by vkolobara on 16.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_RULE_H
#define FUZZY_INFERENCE_SYSTEM_RULE_H


#include "../MembershipFunctions.h"
#include "Clause.h"

class Rule {
protected:
    shared_ptr<Clause> antecedent;
    shared_ptr<MembershipFunction> consequent;
    shared_ptr<BaseOperator::TNorm> tnorm;
public:
    Rule(const shared_ptr<Clause> &antecedent, const shared_ptr<MembershipFunction> &consequent,
         const shared_ptr<BaseOperator::TNorm> &tnorm) : antecedent(antecedent), consequent(consequent), tnorm(tnorm) {}

    MembershipFunction getConclusion();
};


#endif //FUZZY_INFERENCE_SYSTEM_RULE_H
