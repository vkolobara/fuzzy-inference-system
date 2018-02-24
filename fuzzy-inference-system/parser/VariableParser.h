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
    map<string, LanguageVariable*> inputVariables;
    map<string, LanguageVariable*> outputVariables;
    vector<string> inputNames;
    vector<string> outputNames;
public:
    VariableParser() = default;

    ~VariableParser();

    void parseLines(vector<string> lines) override;

    const vector<string> &getOutputNames() const;

    LanguageVariable* getInputVariable(string name);
    LanguageVariable* getOuputVariable(string name);

    const map<string, LanguageVariable*> &getInputVariables() const;

    const map<string, LanguageVariable*> &getOutputVariables() const;

    const vector<string> &getInputNames() const;
};



#endif //FUZZY_INFERENCE_SYSTEM_VARIABLEPARSER_H
