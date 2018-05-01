//
// Created by vkolobara on 5/1/18.
//

#ifndef FUZZY_TIME_SERIES_KNOWLEDGEBASE_H
#define FUZZY_TIME_SERIES_KNOWLEDGEBASE_H


#include "../language_variable/LanguageVariable.h"

struct KnowledgeBase {
    map<string, shared_ptr<LanguageVariable>> variables;

    LanguageVariable* getVariable(string name);

    void setVariableValue(string name, double value);
};


#endif //FUZZY_TIME_SERIES_KNOWLEDGEBASE_H
