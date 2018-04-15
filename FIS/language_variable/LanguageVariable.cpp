#include "LanguageVariable.h"
#include "LanguageTerm.h"

LanguageVariable::LanguageVariable(const string &name, LanguageVariable::Type variableType, double min, double step, double max)
        : name(name), variableType(variableType), min(min), step(step), max(max) {}

void LanguageVariable::addTerm(LanguageTerm *term) {
    terms.push_back(term);
}

LanguageVariable::~LanguageVariable() {
    for (size_t i; i<terms.size(); i++) {
        delete terms.at(i);
    }

}

LanguageTerm *LanguageVariable::getTerm(size_t index) {
    if (index < 0 || index >= terms.size())
        return nullptr;

    return terms.at(index);
}

LanguageTerm *LanguageVariable::getTerm(const string &name) {
    for (size_t i; i<terms.size(); i++) {
        if (terms.at(i)->name == name) {
            return terms.at(i);
        }
    }
    return nullptr;
}

LanguageVariable *LanguageVariable::clone() const {
    auto langVar = new LanguageVariable(this->name, this->variableType, this->min, this->step, this->max);
    langVar->value = this->value;

    for (auto term : terms) {
        langVar->addTerm(term->clone());
    }

    return langVar;
}
