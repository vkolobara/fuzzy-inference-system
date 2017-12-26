//
// Created by vkolobara on 16.12.2017..
//

#include "Rule.h"

shared_ptr<FuzzySet> Rule::getConclusion() {
    return FuzzySet::combine(antecedent->getFuzzySet(), consequense, tnorm);
}
