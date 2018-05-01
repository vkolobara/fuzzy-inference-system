#include "LanguageVariable.h"
#include "LanguageTerm.h"

LanguageVariable::LanguageVariable(const string &name, LanguageVariable::Type variableType, double min, double step, double max)
        : name(name), variableType(variableType), min(min), step(step), max(max) {}

void LanguageVariable::addTerm(LanguageTerm& term) {
    terms.push_back(shared_ptr<LanguageTerm>(&term));
}

LanguageTerm* LanguageVariable::getTerm(size_t index) {
    return terms.at(index).get();
}

LanguageTerm* LanguageVariable::getTerm(const string &name) {
    for (size_t i; i<terms.size(); i++) {
        if (terms.at(i)->name == name) {
            return terms.at(i).get();
        }
    }
    return nullptr;
}