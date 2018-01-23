//
// Created by vkolobara on 12/31/17.
//

#include <iostream>
#include "RulesParser.h"
#include "Helper.h"

void RulesParser::parseLines(vector<string> lines) {

    for (auto line : lines) {
        if (line.empty()) continue;
        if (line[0] == '#') continue;

        vector<string> splitLine = split(line, "->");

        vector<string> simpleClauses = split(splitLine[0], ",");

        vector<shared_ptr<Clause>> clauses;

        for (auto clauseS : simpleClauses) {
            clauses.push_back(parseSimpleClause(clauseS, inputVariables));
        }

        auto antecedent = make_shared<AndClause>(clauses, tnorm);
        auto consequense = parseConsequense(trim(splitLine[1]), outputVariables);

        rules[trim(split(trim(splitLine[1]), "=")[0])].push_back(make_shared<Rule>(antecedent, consequense, tnorm));
    }

}

const shared_ptr<BaseOperator::TNorm> &RulesParser::getTnorm() const {
    return tnorm;
}

RulesParser::RulesParser(const map<string, shared_ptr<LanguageVariable>> &inputVariables,
                         const map<string, shared_ptr<LanguageVariable>> &outputVariables,
                         const shared_ptr<BaseOperator::TNorm> &tnorm) : inputVariables(inputVariables),
                                                                         outputVariables(outputVariables),
                                                                         tnorm(tnorm) {}

const map<string, shared_ptr<LanguageVariable>> &RulesParser::getInputVariables() const {
    return inputVariables;
}

const map<string, shared_ptr<LanguageVariable>> &RulesParser::getOutputVariables() const {
    return outputVariables;
}

const map<string, vector<shared_ptr<Rule>>> &RulesParser::getRules() const {
    return rules;
}
