#include <iostream>
#include <memory>
#include "fuzzyset/MembershipFunction.h"
#include "inference/Clause.h"
#include "inference/Defuzzifier.h"
#include "inference/InferenceSystem.h"
#include "parser/VariableParser.h"
#include "parser/RulesParser.h"

using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Expecting 2 arguments: path to lang_variables.conf conf, path to rules.conf conf!\n";
        return -1;
    }

    auto variableParser = make_shared<VariableParser>();
    auto defuzzifier = make_shared<COADefuzzifier>();

    variableParser->parse(argv[1]);

    auto rulesParser = make_shared<RulesParser>(variableParser->getLangVariables(), make_shared<Zadeh::TNorm>());

    rulesParser->parse(argv[2]);

    list<string> names;

    for (int i=0; i<variableParser->getLangVariables().size()-1; i++) {
        auto var = variableParser->getLangVariables()[i]->getName();
        names.push_back(var);
    }

    auto input = make_shared<FuzzyInput>(names);

    auto inferenceSystem = make_shared<MamdaniInferenceSystem>(rulesParser->getRules(), make_shared<Zadeh::SNorm>(),
                                                               defuzzifier);

    double height, weight;

    while (cin >> height >> weight) {
        input->setValue("height", make_shared<DomainElement>(DomainElement({height})));
        input->setValue("weight", make_shared<DomainElement>(DomainElement({weight})));

        for (auto rule : inferenceSystem->getRules()) {
            cout << defuzzifier->defuzzify(rule->getConclusion(input)) << endl;
        }

        cout << "PARSED INF SYSTEM CONCLUSION:\n" << inferenceSystem->getConclusion(input) << endl;
    }


    return 0;
}
