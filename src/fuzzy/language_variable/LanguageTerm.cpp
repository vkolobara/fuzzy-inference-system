//
// Created by vkolobara on 8/13/17.
//

#include "LanguageTerm.h"

LanguageTerm::LanguageTerm() {};

LanguageTerm::LanguageTerm(const string &name, const shared_ptr<MembershipFunction> &meaning) : name(name),
                                                                                                meaning(meaning) {}

shared_ptr<MembershipFunction> LanguageTerm::getMeaning() {
    return meaning;
}

string LanguageTerm::getName() {
    return name;
}
