//
// Created by vkolobara on 12/31/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_RULESPARSER_H
#define FUZZY_INFERENCE_SYSTEM_RULESPARSER_H


#include "Parser.h"
#include "../inference/Rule.h"
#include <memory>


class RulesParser : public Parser {
private:
    vector<shared_ptr<Rule>> rules;
    map<string, shared_ptr<LanguageVariable>> variables;
    shared_ptr<BaseOperator::TNorm> tnorm;
public:
    RulesParser(vector<shared_ptr<LanguageVariable>> langVars, shared_ptr<BaseOperator::TNorm> tnorm);

    void parseLines(vector<string> lines) override;

    const vector<shared_ptr<Rule>> &getRules() const;

    const map<string, shared_ptr<LanguageVariable>> &getVariables() const;

    const shared_ptr<BaseOperator::TNorm> &getTnorm() const;
};


#endif //FUZZY_INFERENCE_SYSTEM_RULESPARSER_H
