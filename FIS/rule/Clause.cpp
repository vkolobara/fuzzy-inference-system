//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "Clause.h"

#include <utility>

double Clause::membership() {
    return languageVariable->terms.at(termIndex)->membership(languageVariable->value);
}

Clause::Clause(shared_ptr<LanguageVariable> languageVariable, uint termIndex) {
    this->languageVariable = std::move(languageVariable);
    this->termIndex = termIndex;
}
