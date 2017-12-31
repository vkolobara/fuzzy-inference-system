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

        auto name = lineSplit[0];

        auto domain = parseDomain(lineSplit[1]);

        index++;

        vector<shared_ptr<LanguageTerm>> terms;

        while (index < size && !lines[index].empty()) {
            terms.push_back(parseTerm(lines[index], domain));
            index++;
        }

        langVariables.push_back(make_shared<LanguageVariable>(name, domain, terms));
        index++;
    }

}

const vector<shared_ptr<LanguageVariable>> &VariableParser::getLangVariables() const {
    return langVariables;
}
