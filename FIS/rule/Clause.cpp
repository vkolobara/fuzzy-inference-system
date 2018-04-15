//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "Clause.h"

double Clause::membership() {
    return languageTerm->membership(languageVariable->value);
}

Clause::Clause(LanguageVariable *languageVariable, LanguageTerm *languageTerm) : languageVariable(languageVariable),
                                                                                 languageTerm(languageTerm) {}

Clause::~Clause() {
    delete languageTerm;
    delete languageVariable;

}

Clause *Clause::clone() const {
    return new Clause(this->languageVariable->clone(), this->languageTerm->clone());
}
