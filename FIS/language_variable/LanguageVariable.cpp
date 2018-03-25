//
// Created by vkolobara on 8/7/17.
//

#include "LanguageVariable.h"


LanguageVariable::LanguageVariable(string name, Domain* domain, vector<LanguageTerm*> term_vector)
        : name(
        std::move(name)), domain(domain) {
    for (LanguageTerm* term : term_vector) {
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

FuzzySet* LanguageVariable::getMeaning(string term) {
    return terms[term]->getMeaning();
}

Domain* LanguageVariable::getDomain() {
    return domain;
}

LanguageTerm* LanguageVariable::getLanguageTerm(string term) {
    return terms[term];
}
