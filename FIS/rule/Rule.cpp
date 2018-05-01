//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "Rule.h"

Rule::Rule(Antecedent& antecedent, Consequent& consequent) {
    this->antecedent = unique_ptr<Antecedent>(&antecedent);
    this->consequent = shared_ptr<Consequent>(&consequent);
}