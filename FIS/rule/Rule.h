//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#ifndef FUZZY_TIME_SERIES_RULE_H
#define FUZZY_TIME_SERIES_RULE_H


#include "Antecedent.h"

struct Rule {
    unique_ptr<Antecedent> antecedent;
    shared_ptr<Clause> consequent;

    Rule(Antecedent& antecedent, shared_ptr<Clause> consequent);
};


#endif //FUZZY_TIME_SERIES_RULE_H
