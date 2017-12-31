#include <iostream>
#include <memory>
#include "fuzzy/MembershipFunction.h"
#include "fuzzy/inference/Clause.h"
#include "fuzzy/Defuzzifier.h"
#include "fuzzy/inference/InferenceSystem.h"
#include "fuzzy/parser/VariableParser.h"
#include "fuzzy/parser/RulesParser.h"

using namespace std;

int main() {
    list<string> names{"height", "weight"};
    auto input = make_shared<FuzzyInput>(names);

    input->setValue("height", make_shared<DomainElement>(DomainElement({150})));
    input->setValue("weight", make_shared<DomainElement>(DomainElement({85})));

    auto defuzzifier = make_shared<COADefuzzifier>();


    auto variableParser = make_shared<VariableParser>();

    vector<string> lines{"height\t0,0.01,250", "short\tL\t40,175", "tall\tGAMMA\t140,185",
                         "", "weight\t1,0.01,250", "light\tL\t50,100", "heavy\tGAMMA\t70,130", "",
                         "output\t0,1,100", "small\tPI\t0,15,30,40", "large\tPI\t30,40,50,80", ""};

    variableParser->parseLines(lines);

    auto rulesParser = make_shared<RulesParser>(variableParser->getLangVariables(), make_shared<Zadeh::TNorm>());

    vector<string> ruleLines{"height=short, weight=light -> output=small",
                             "height=tall,  weight=heavy -> output=large"};

    rulesParser->parseLines(ruleLines);

    auto inferenceSystem = make_shared<MamdaniInferenceSystem>(rulesParser->getRules(), make_shared<Zadeh::SNorm>(),
                                                               defuzzifier);

    cout << "PARSED INF SYSTEM CONCLUSION:\n" << inferenceSystem->getConclusion(input) << endl;

    return 0;
}
