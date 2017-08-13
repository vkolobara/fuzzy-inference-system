//
// Created by vkolobara on 8/7/17.
//

#include "LanguageVariable.h"

LanguageVariable::LanguageVariable(string name, Domain domain, vector<LanguageTerm> terms) :  name(name), domain(domain) {
    for (LanguageTerm term : terms) {
        this->terms[term.getName()] = term;
    }
}

string LanguageVariable::getName() {
    return name;
}

vector<string> LanguageVariable::getTermNames() {
    vector<string> names;

    for (auto const& name: this->terms) {
        names.push_back(name.first);
    }

    return names;
}

shared_ptr<MembershipFunction> LanguageVariable::getMembershipFunction(string term) {
    return this->terms[term].getMeaning();
}

Domain LanguageVariable::getDomain() {
    return domain;
}