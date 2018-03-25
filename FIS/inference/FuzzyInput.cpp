//
// Created by vkolobara on 12.12.2017..
//

#include <memory>
#include "FuzzyInput.h"

FuzzyInput::FuzzyInput(vector<string> names) {
    for (string name : names) {
        setValue(name, 0.0);
    }
}

void FuzzyInput::setValue(string languageVariable, double value) {
    currentValues[languageVariable] = value;
}

double FuzzyInput::getValue(string languageVariable) {
    return currentValues[languageVariable];
}

FuzzyInput::~FuzzyInput() {
    currentValues.clear();
}
