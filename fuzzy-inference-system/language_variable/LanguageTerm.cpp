//
// Created by vkolobara on 8/13/17.
//

#include "LanguageTerm.h"


LanguageTerm::LanguageTerm() = default;

LanguageTerm::LanguageTerm(const string &name, FuzzySet* meaning) : name(name),
                                                                                      meaning(meaning) {}

FuzzySet* LanguageTerm::getMeaning() {
    return meaning;
}

string LanguageTerm::getName() {
    return name;
}

LanguageTerm::~LanguageTerm() {
    delete meaning;

}
