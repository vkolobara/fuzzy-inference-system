//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#ifndef FUZZY_TIME_SERIES_RULE_H
#define FUZZY_TIME_SERIES_RULE_H


#include "Antecedent.h"

struct Rule {
    Antecedent* antecedent;
    Clause* consequent;

    Rule(Antecedent *antecedent, Clause *consequent);
    Rule* clone() const;
    ~Rule();

};


#endif //FUZZY_TIME_SERIES_RULE_H
