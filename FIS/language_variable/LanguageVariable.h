//
// Created by vkolobara on 8/7/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_LANGUAGEVARIABLE_H
#define FUZZY_INFERENCE_SYSTEM_LANGUAGEVARIABLE_H

#include <vector>
#include <map>
#include "string"
#include "LanguageTerm.h"


using namespace std;

struct LanguageVariable {

    enum Type {
        Input,
        Output
    };

    string name;
    vector<LanguageTerm*> terms;
    Type variableType;

    double value;
    double min;
    double step;
    double max;

    LanguageVariable(const string &name, Type variableType, double min, double step, double max);

    ~LanguageVariable();

    LanguageVariable* clone() const;

    void addTerm(LanguageTerm* term);

    LanguageTerm* getTerm(size_t index);
    LanguageTerm* getTerm(const string &name);
};


#endif //FUZZY_INFERENCE_SYSTEM_LANGUAGEVARIABLE_H
