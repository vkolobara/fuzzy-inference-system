//
// Created by vkolobara on 12.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_FUZZYINPUT_H
#define FUZZY_INFERENCE_SYSTEM_FUZZYINPUT_H

#include "string"
#include <memory>
#include <map>
#include <list>
#include <vector>

using namespace std;

class FuzzyInput {
protected:
    map<string, double> currentValues;
public:
    FuzzyInput(vector <string> names);
    ~FuzzyInput();

    void setValue(string languageVariable, double value);

    double getValue(string languageVariable);
};


#endif //FUZZY_INFERENCE_SYSTEM_FUZZYINPUT_H
