//
// Created by vkolobara on 8/7/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_LANGUAGEVARIABLE_H
#define FUZZY_INFERENCE_SYSTEM_LANGUAGEVARIABLE_H

#include <vector>
#include <map>
#include "string"
#include "../MembershipFunctions.h"
#include "../domain/Domain.h"
#include "LanguageTerm.h"


using namespace std;

class LanguageVariable {
private:
    string name;
    shared_ptr<Domain> domain;
    map<string, LanguageTerm> terms;
public:
    LanguageVariable(string name, shared_ptr<Domain> domain, vector<LanguageTerm> terms);
    string getName();
    shared_ptr<Domain> getDomain();
    vector<string> getTermNames();
    shared_ptr<MembershipFunction> getMembershipFunction(string term);
};


#endif //FUZZY_INFERENCE_SYSTEM_LANGUAGEVARIABLE_H
