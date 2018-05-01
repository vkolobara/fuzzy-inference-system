//
// Created by vkolobara on 5/1/18.
//

#include "KnowledgeBase.h"

void KnowledgeBase::setVariableValue(string name, double value) {
    getVariable(name)->value = value;
}

LanguageVariable* KnowledgeBase::getVariable(string name) {
    return variables.at(name).get();
}
