//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "Rule.h"

Rule::Rule(Antecedent *antecedent, Clause *consequent) : antecedent(antecedent), consequent(consequent) {}

Rule::~Rule() {
    delete antecedent;
    delete consequent;
}

Rule *Rule::clone() const {
    return new Rule(this->antecedent->clone(), this->consequent->clone());
}
