//
// Created by vkolobara on 12.12.2017..
//

#include "FuzzyInput.h"

FuzzyInput::FuzzyInput(list<string> names) {
    for (string name : names) {
        setValue(name, 0);
    }
}

void FuzzyInput::setValue(string languageVariable, double value) {
    currentValues[languageVariable] = value;
}

double FuzzyInput::getValue(string languageVariable) {
    return currentValues[languageVariable];
}

map<string, double> FuzzyInput::getAllValues() {
    return map<string, double>(currentValues);
}