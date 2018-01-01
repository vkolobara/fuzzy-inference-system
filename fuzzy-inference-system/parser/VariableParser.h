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
    vector<shared_ptr<LanguageVariable>> langVariables;
public:
    VariableParser() = default;

    void parseLines(vector<string> lines) override;

    const vector<shared_ptr<LanguageVariable>> &getLangVariables() const;
};


#endif //FUZZY_INFERENCE_SYSTEM_VARIABLEPARSER_H
