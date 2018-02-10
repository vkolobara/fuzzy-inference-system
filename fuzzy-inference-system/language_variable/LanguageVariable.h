//
// Created by vkolobara on 8/7/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_LANGUAGEVARIABLE_H
#define FUZZY_INFERENCE_SYSTEM_LANGUAGEVARIABLE_H

#include <vector>
#include <map>
#include "string"
#include "../fuzzyset/MembershipFunction.h"
#include "../domain/Domain.h"
#include "LanguageTerm.h"


using namespace std;

class LanguageVariable {
private:
    string name;
    Domain* domain;
    map<string, LanguageTerm*> terms;
public:
    LanguageVariable(string name, Domain* domain, vector<LanguageTerm*> terms);

    string getName();

    Domain* getDomain();

    vector<string> getTermNames();

    FuzzySet* getMeaning(string term);

    LanguageTerm* getLanguageTerm(string term);
};


#endif //FUZZY_INFERENCE_SYSTEM_LANGUAGEVARIABLE_H
