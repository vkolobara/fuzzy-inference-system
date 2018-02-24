//
// Created by vkolobara on 12.12.2017..
//

#include <memory>
#include "FuzzyInput.h"

FuzzyInput::FuzzyInput(vector<string> names) {
    for (string name : names) {
        setValue(name, new DomainElement({0}));
    }
}

void FuzzyInput::setValue(string languageVariable, DomainElement* value) {
    delete currentValues[languageVariable];
    currentValues[languageVariable] = value;
}

DomainElement* FuzzyInput::getValue(string languageVariable) {
    return currentValues[languageVariable];
}

FuzzyInput::~FuzzyInput() {
    for (auto val : currentValues) {
        delete val.second;
    }

    currentValues.clear();
}
