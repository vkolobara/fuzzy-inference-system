//
// Created by vkolobara on 8/13/17.
//

#include "LanguageTerm.h"


LanguageTerm::LanguageTerm() = default;

LanguageTerm::LanguageTerm(const string &name, const shared_ptr<FuzzySet> &meaning) : name(name),
                                                                                      meaning(meaning) {}

shared_ptr<FuzzySet> LanguageTerm::getMeaning() {
    return meaning;
}

string LanguageTerm::getName() {
    return name;
}
