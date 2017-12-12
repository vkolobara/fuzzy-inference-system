//
// Created by vkolobara on 12.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_CLAUSE_H
#define FUZZY_INFERENCE_SYSTEM_CLAUSE_H


#include "../language_variable/LanguageVariable.h"
#include "FuzzyInput.h"

class Clause {
public:
    virtual double calculateMembership(FuzzyInput fuzzyInput) = 0;
};


#endif //FUZZY_INFERENCE_SYSTEM_CLAUSE_H
