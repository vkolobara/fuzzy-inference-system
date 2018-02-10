//
// Created by vkolobara on 12/31/17.
//

#include <sstream>
#include "VariableParser.h"
#include "Helper.h"


void VariableParser::parseLines(vector<string> lines) {

    auto index = 0;
    auto size = lines.size();

    while (index < size) {
        vector<string> lineSplit = split(lines[index], "\t");

        auto inOut = lineSplit[0];

        auto name = lineSplit[1];

        auto domain = parseDomain(lineSplit[2]);

        index++;

        vector<LanguageTerm*> terms;

        while (index < size && !lines[index].empty()) {
            terms.push_back(parseTerm(lines[index], domain));
            index++;
        }

        auto var = new LanguageVariable(name, domain, terms);

        if (inOut == "IN") {
            inputVariables[name] = var;
            inputNames.push_back(name);
        }
        else {
            outputVariables[name] = var;
            outputNames.push_back(name);
        }

        index++;
    }

}

LanguageVariable* VariableParser::getInputVariable(string name) {
    return inputVariables[name];
}

LanguageVariable* VariableParser::getOuputVariable(string name) {
    return outputVariables[name];
}

const map<string, LanguageVariable*> &VariableParser::getInputVariables() const {
    return inputVariables;
}

const map<string, LanguageVariable*> &VariableParser::getOutputVariables() const {
    return outputVariables;
}

const vector<string> &VariableParser::getOutputNames() const {
    return outputNames;
}

const vector<string> &VariableParser::getInputNames() const {
    return inputNames;
}


