//
// Created by vkolobara on 12.12.2017..
//

#include <memory>
#include "FuzzyInput.h"

FuzzyInput::FuzzyInput(vector<string> names) {
    for (string name : names) {
        setValue(name, make_shared<DomainElement>(DomainElement({0})));
    }
}

void FuzzyInput::setValue(string languageVariable, shared_ptr<DomainElement> value) {
    currentValues[languageVariable] = value;
}

shared_ptr<DomainElement> FuzzyInput::getValue(string languageVariable) {
    return currentValues[languageVariable];
}
