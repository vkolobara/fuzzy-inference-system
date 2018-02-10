//
// Created by vkolobara on 12.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_FUZZYINPUT_H
#define FUZZY_INFERENCE_SYSTEM_FUZZYINPUT_H

#include "string"
#include <memory>
#include "../domain/DomainElement.h"
#include <map>
#include <list>

using namespace std;

class FuzzyInput {
protected:
    map<string, DomainElement*> currentValues;
public:
    FuzzyInput(vector <string> names);

    void setValue(string languageVariable, DomainElement* value);

    DomainElement* getValue(string languageVariable);
};


#endif //FUZZY_INFERENCE_SYSTEM_FUZZYINPUT_H
