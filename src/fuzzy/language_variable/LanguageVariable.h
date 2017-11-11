//
// Created by vkolobara on 8/7/17.
//

#ifndef DIPLOMSKI_LANGUAGEVARIABLE_H
#define DIPLOMSKI_LANGUAGEVARIABLE_H

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
    Domain domain;
    map<string, LanguageTerm> terms;
public:
    LanguageVariable(string name, Domain domain, vector<LanguageTerm> terms);
    string getName();
    Domain getDomain();
    vector<string> getTermNames();
    shared_ptr<MembershipFunction> getMembershipFunction(string term);
};


#endif //DIPLOMSKI_LANGUAGEVARIABLE_H
