//
// Created by vkolobara on 16.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_RULE_H
#define FUZZY_INFERENCE_SYSTEM_RULE_H


#include <utility>

#include "../fuzzyset/MembershipFunction.h"
#include "Clause.h"
#include "../fuzzyset/FuzzySet.h"

class Rule {
protected:
    Clause* antecedent;
    FuzzySet* consequense;
    BaseOperator::TNorm* tnorm;
public:
    Rule(Clause* antecedent, FuzzySet* consequense,
         BaseOperator::TNorm* tnorm) : antecedent(antecedent), consequense(consequense), tnorm(tnorm) {};


    FuzzySet* getConclusion(FuzzyInput* fuzzyInput);
};


#endif //FUZZY_INFERENCE_SYSTEM_RULE_H
