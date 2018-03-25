//
// Created by vkolobara on 12/31/17.
//

#include <iostream>
#include <utility>
#include "RulesParser.h"
#include "Helper.h"

void RulesParser::parseLines(vector<string> lines) {

    for (auto line : lines) {
        if (line.empty()) continue;
        if (line[0] == '#') continue;

        vector<string> splitLine = split(line, "->");

        vector<string> simpleClauses = split(splitLine[0], ",");

        vector<Clause*> clauses;

        for (auto clauseS : simpleClauses) {
            clauses.push_back(parseSimpleClause(clauseS, inputVariables));
        }

        auto antecedent = new AndClause(clauses, tnorm);
        auto consequense = parseConsequense(trim(splitLine[1]), outputVariables);

        rules[trim(split(trim(splitLine[1]), "=")[0])].emplace_back(Rule(antecedent, consequense, tnorm));
    }

}

BaseOperator::TNorm* RulesParser::getTnorm() {
    return tnorm;
}

RulesParser::RulesParser(map<string, LanguageVariable *> inputVariables,
                         map<string, LanguageVariable *> outputVariables,
                         BaseOperator::TNorm* tnorm) : inputVariables(std::move(inputVariables)),
                                                                         outputVariables(std::move(outputVariables)),
                                                                         tnorm(tnorm) {}

const map<string, LanguageVariable*> &RulesParser::getInputVariables() const {
    return inputVariables;
}

const map<string, LanguageVariable*> &RulesParser::getOutputVariables() const {
    return outputVariables;
}

const map<string, vector<Rule>> &RulesParser::getRules() const {
    return rules;
}

RulesParser::~RulesParser() {
    delete tnorm;
}
