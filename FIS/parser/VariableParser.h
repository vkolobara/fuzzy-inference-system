//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#ifndef FUZZY_TIME_SERIES_VARIABLEPARSER_H
#define FUZZY_TIME_SERIES_VARIABLEPARSER_H

#include "Parser.h"
#include "../language_variable/LanguageVariable.h"

struct VariableParser : public Parser {

    vector<shared_ptr<LanguageVariable>> inputVariables;
    vector<shared_ptr<LanguageVariable>> outputVariables;

    void parse(string fileContents) override;

private:
    LanguageVariable* parseLanguageVariable(vector<string> lines);
    LanguageTerm* parseLanguageTerm(string line);
};


#endif //FUZZY_TIME_SERIES_VARIABLEPARSER_H
