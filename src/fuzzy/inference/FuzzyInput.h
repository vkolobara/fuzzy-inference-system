//
// Created by vkolobara on 12.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_FUZZYINPUT_H
#define FUZZY_INFERENCE_SYSTEM_FUZZYINPUT_H

#include "string"
#include <map>
#include <list>

using namespace std;

class FuzzyInput {
protected:
    map<string, double> currentValues;
public:
    FuzzyInput(list<string> names);
    void setValue(string languageVariable, double value);
    double getValue(string languageVariable);
    map<string, double> getAllValues();
};


#endif //FUZZY_INFERENCE_SYSTEM_FUZZYINPUT_H
