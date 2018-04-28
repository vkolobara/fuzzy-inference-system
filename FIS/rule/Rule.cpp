//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "Rule.h"

Rule::Rule(Antecedent& antecedent, shared_ptr<Clause> consequent) {
    this->antecedent = make_unique<Antecedent>(antecedent);
    this->consequent = consequent;
}