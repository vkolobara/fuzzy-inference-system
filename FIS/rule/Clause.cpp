//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "Clause.h"

double Clause::membership() {
    return languageTerm->membership(languageVariable->value);
}

Clause::Clause(shared_ptr<LanguageVariable> languageVariable, shared_ptr<LanguageTerm> languageTerm) {
    this->languageVariable = languageVariable;
    this->languageTerm = languageTerm;
}
