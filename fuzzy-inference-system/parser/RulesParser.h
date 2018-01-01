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
    map<string, vector<shared_ptr<Rule>>> rules;
    map<string, shared_ptr<LanguageVariable>> inputVariables;
    map<string, shared_ptr<LanguageVariable>> outputVariables;
    shared_ptr<BaseOperator::TNorm> tnorm;
public:
    RulesParser(const map<string, shared_ptr<LanguageVariable>> &inputVariables,
                const map<string, shared_ptr<LanguageVariable>> &outputVariables,
                const shared_ptr<BaseOperator::TNorm> &tnorm);

    void parseLines(vector<string> lines) override;

    const map<string, vector<shared_ptr<Rule>>> &getRules() const;

    const map<string, shared_ptr<LanguageVariable>> &getInputVariables() const;

    const map<string, shared_ptr<LanguageVariable>> &getOutputVariables() const;

    const shared_ptr<BaseOperator::TNorm> &getTnorm() const;
};


#endif //FUZZY_INFERENCE_SYSTEM_RULESPARSER_H
