//
// Created by vkolobara on 8/13/17.
//

#ifndef DIPLOMSKI_LANGUAGETERM_H
#define DIPLOMSKI_LANGUAGETERM_H

#include <string>
#include <map>
#include <memory>
#include "../MembershipFunctions.h"

using namespace std;

class LanguageTerm {
private:
    string name;
    shared_ptr<MembershipFunction> meaning;
public:
    LanguageTerm();
    LanguageTerm(const string &name, const shared_ptr<MembershipFunction> &meaning);
    shared_ptr<MembershipFunction> getMeaning();
    string getName();
};

#endif //DIPLOMSKI_LANGUAGETERM_H
