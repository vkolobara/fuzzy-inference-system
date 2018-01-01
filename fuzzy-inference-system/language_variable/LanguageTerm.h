//
// Created by vkolobara on 8/13/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_LANGUAGETERM_H
#define FUZZY_INFERENCE_SYSTEM_LANGUAGETERM_H


#include <string>
#include <map>
#include <memory>
#include "../fuzzyset/MembershipFunction.h"
#include "../fuzzyset/FuzzySet.h"

using namespace std;

class LanguageTerm {
private:
    string name;
    shared_ptr<FuzzySet> meaning;
public:
    LanguageTerm();

    LanguageTerm(const string &name, const shared_ptr<FuzzySet> &meaning);

    shared_ptr<FuzzySet> getMeaning();

    string getName();
};

#endif //FUZZY_INFERENCE_SYSTEM_LANGUAGETERM_H
