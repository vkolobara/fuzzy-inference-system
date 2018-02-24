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

    auto variableParser = VariableParser();
    auto defuzzifier = COADefuzzifier();

    variableParser.parse(argv[1]);

    auto rulesParser = RulesParser(variableParser.getInputVariables(),
                                                variableParser.getOutputVariables(),
                                                new Zadeh::TNorm());

    rulesParser.parse(argv[2]);

    auto inputNames = variableParser.getInputNames();
    auto outputNames = variableParser.getOutputNames();

    auto input = new FuzzyInput(inputNames);

    map<string, InferenceSystem*> inferenceSystems;

    for (auto ruleSet : rulesParser.getRules()) {
        inferenceSystems[ruleSet.first] = new MamdaniInferenceSystem(ruleSet.second, new Zadeh::SNorm(), &defuzzifier);
    }


    double inputs[inputNames.size()];

    int index = 0;
    while (cin >> inputs[index]) {

        input->setValue(inputNames[index], new DomainElement({inputs[index]}));

        index = static_cast<int>((index + 1) % inputNames.size());

        if (index == 0) {
            for (auto outName : outputNames) {
                cout << (int) inferenceSystems[outName]->getConclusion(input) << " ";
            }
            cout << flush << endl;
        }

    }


    return 0;
}
