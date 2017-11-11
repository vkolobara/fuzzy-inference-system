//
// Created by vkolobara on 8/13/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_LANGUAGETERM_H
#define FUZZY_INFERENCE_SYSTEM_LANGUAGETERM_H


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

#endif //FUZZY_INFERENCE_SYSTEM_LANGUAGETERM_H
