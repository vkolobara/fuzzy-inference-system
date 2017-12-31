//
// Created by vkolobara on 8/7/17.
//

#include "LanguageVariable.h"


LanguageVariable::LanguageVariable(string name, shared_ptr<Domain> domain, vector<shared_ptr<LanguageTerm>> term_vector)
        : name(
        std::move(name)), domain(std::move(domain)) {
    for (const shared_ptr<LanguageTerm> &term : term_vector) {
        terms[term->getName()] = term;
    }
}

string LanguageVariable::getName() {
    return name;
}

vector<string> LanguageVariable::getTermNames() {
    vector<string> names;

    for (auto const &name: this->terms) {
        names.push_back(name.first);
    }

    return names;
}

shared_ptr<FuzzySet> LanguageVariable::getMeaning(string term) {
    return terms[term]->getMeaning();
}

shared_ptr<Domain> LanguageVariable::getDomain() {
    return domain;
}

shared_ptr<LanguageTerm> LanguageVariable::getLanguageTerm(string term) {
    return shared_ptr<LanguageTerm>(terms[term]);
}
