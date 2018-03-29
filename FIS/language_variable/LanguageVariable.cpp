//
// Created by vkolobara on 8/7/17.
//

#include "LanguageVariable.h"


LanguageVariable::LanguageVariable(string name, shared_ptr<Domain> domain, vector<shared_ptr<LanguageTerm>> term_vector)
        : name(
        std::move(name)), domain(domain) {
    for (auto term : term_vector) {
        terms[term->getName()] = term;
        termNames.push_back(term->getName());
    }
}

string LanguageVariable::getName() {
    return name;
}

vector<string> LanguageVariable::getTermNames() {
    return termNames;
}

shared_ptr<FuzzySet> LanguageVariable::getMeaning(string term) {
    return terms[term]->getMeaning();
}

shared_ptr<Domain> LanguageVariable::getDomain() {
    return domain;
}

shared_ptr<LanguageTerm> LanguageVariable::getLanguageTerm(string term) {
    return terms[term];
}
