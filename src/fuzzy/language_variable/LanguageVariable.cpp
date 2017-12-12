//
// Created by vkolobara on 8/7/17.
//

#include "LanguageVariable.h"


LanguageVariable::LanguageVariable(string name, DomainRange domain, vector<LanguageTerm> term_vector) :  name(name), domain(domain) {
    for (LanguageTerm term : term_vector) {
        terms[term.getName()] = term;
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
    return terms[term].getMeaning();
}

DomainRange LanguageVariable::getDomain() {
    return domain;
}