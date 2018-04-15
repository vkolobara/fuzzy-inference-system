//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "VariableParser.h"
#include "Helper.h"


void VariableParser::parse(string fileContent) {
    vector<string> langVars = splitString(fileContent, "\n\n");

    for (auto langVar : langVars) {
        auto var = parseLanguageVariable(splitString(langVar, "\n"));
        if (var->variableType == LanguageVariable::Type::Output) {
            this->outputVariables.push_back(var);
        } else {
            this->inputVariables.push_back(var);
        }
    }

}

LanguageTerm *VariableParser::parseLanguageTerm(string line) {
    vector<string> splitted;
    split(line, '\t', splitted);

    auto name = splitted[0];
    auto termType = splitted[1];

    vector<string> params;
    split(splitted[2], ',', params);

    LanguageTerm* term = nullptr;

    if (termType == "PI") {
        auto alpha = stod(params[0]);
        auto beta = stod(params[1]);
        auto gamma = stod(params[2]);
        auto delta = stod(params[3]);

        term = new LinearLanguageTerm::PiLanguageTerm(name, alpha, beta, gamma, delta);
    }

    return term;
}

LanguageVariable *VariableParser::parseLanguageVariable(vector<string> lines) {

    vector<string> line;
    split(lines[0], '\t', line);

    auto varType = LanguageVariable::Type::Input;
    auto varTypeStr = line[0];
    auto name = line[1];

    vector<string> domain;
    split(line[2], ',', domain);

    auto min = stod(domain[0]);
    auto step = stod(domain[1]);
    auto max = stod(domain[2]);

    if (varTypeStr == "OUT") varType = LanguageVariable::Type::Output;

    LanguageVariable* langVar = new LanguageVariable(name, varType, min, step, max);

    for (auto i = 1; i<lines.size(); i++) {
        langVar->addTerm(parseLanguageTerm(lines[i]));
    }

    return langVar;
}
