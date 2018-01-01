//
// Created by vkolobara on 12/31/17.
//

#include <iostream>
#include "RulesParser.h"
#include "Helper.h"

void RulesParser::parseLines(vector<string> lines) {

    for (auto line : lines) {
        if (line.empty()) continue;

        vector<string> splitLine = split(line, "->");

        vector<string> simpleClauses = split(splitLine[0], ",");

        vector<shared_ptr<Clause>> clauses;

        for (auto clauseS : simpleClauses) {
            clauses.push_back(parseSimpleClause(clauseS, variables));
        }

        auto antecedent = make_shared<AndClause>(clauses, tnorm);
        auto consequense = parseConsequense(trim(splitLine[1]), variables);

        rules.push_back(make_shared<Rule>(antecedent, consequense, tnorm));
    }

}

RulesParser::RulesParser(vector<shared_ptr<LanguageVariable>> langVars, shared_ptr<BaseOperator::TNorm> tnorm) : tnorm(
        tnorm) {
    for (auto var : langVars) {
        variables[var->getName()] = var;
    }
}

const vector<shared_ptr<Rule>> &RulesParser::getRules() const {
    return rules;
}

const map<string, shared_ptr<LanguageVariable>> &RulesParser::getVariables() const {
    return variables;
}

const shared_ptr<BaseOperator::TNorm> &RulesParser::getTnorm() const {
    return tnorm;
}
