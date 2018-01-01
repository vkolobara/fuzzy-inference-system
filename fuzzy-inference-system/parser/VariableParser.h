//
// Created by vkolobara on 12/31/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_VARIABLEPARSER_H
#define FUZZY_INFERENCE_SYSTEM_VARIABLEPARSER_H

#include <memory>
#include "Parser.h"
#include "../language_variable/LanguageVariable.h"

class VariableParser : public Parser {
private:
    map<string, shared_ptr<LanguageVariable>> inputVariables;
    map<string, shared_ptr<LanguageVariable>> outputVariables;
    vector<string> inputNames;
    vector<string> outputNames;
public:
    VariableParser() = default;

    void parseLines(vector<string> lines) override;

    const vector<string> &getOutputNames() const;

    shared_ptr<LanguageVariable> getInputVariable(string name);
    shared_ptr<LanguageVariable> getOuputVariable(string name);

    const map<string, shared_ptr<LanguageVariable>> &getInputVariables() const;

    const map<string, shared_ptr<LanguageVariable>> &getOutputVariables() const;

    const vector<string> &getInputNames() const;
};



#endif //FUZZY_INFERENCE_SYSTEM_VARIABLEPARSER_H
