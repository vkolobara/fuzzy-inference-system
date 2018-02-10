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
    map<string, vector<Rule*>> rules;
    map<string, LanguageVariable*> inputVariables;
    map<string, LanguageVariable*> outputVariables;
    BaseOperator::TNorm* tnorm;
public:
    RulesParser(map<string, LanguageVariable*> inputVariables,
                map<string, LanguageVariable*> outputVariables,
                BaseOperator::TNorm* tnorm);

    void parseLines(vector<string> lines) override;

    const map<string, vector<Rule*>> &getRules() const;

    const map<string, LanguageVariable*> &getInputVariables() const;

    const map<string, LanguageVariable*> &getOutputVariables() const;

    BaseOperator::TNorm* getTnorm();
};


#endif //FUZZY_INFERENCE_SYSTEM_RULESPARSER_H
