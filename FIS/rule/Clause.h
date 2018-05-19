//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#ifndef FUZZY_TIME_SERIES_CLAUSE_H
#define FUZZY_TIME_SERIES_CLAUSE_H


#include "../language_variable/LanguageVariable.h"
#include "../language_variable/LanguageTerm.h"

struct Clause {
    shared_ptr<LanguageVariable> languageVariable;
    unsigned int termIndex;

    Clause(shared_ptr<LanguageVariable> languageVariable, unsigned int termIndex);
    double membership();
};


#endif //FUZZY_TIME_SERIES_CLAUSE_H
