//
// Created by vkolobara on 16.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_RULE_H
#define FUZZY_INFERENCE_SYSTEM_RULE_H


#include "../FuzzySet.h"
#include "Clause.h"

class Rule {
protected:
    shared_ptr<Clause> antecedent;
    shared_ptr<FuzzySet> consequense;
    shared_ptr<BaseOperator::TNorm> tnorm;
public:
    Rule(const shared_ptr<Clause> &antecedent, const shared_ptr<FuzzySet> &consequense,
         const shared_ptr<BaseOperator::TNorm> &tnorm) : antecedent(antecedent), consequense(consequense), tnorm(tnorm) {};


    unique_ptr<FuzzySet> getConclusion();
};


#endif //FUZZY_INFERENCE_SYSTEM_RULE_H
