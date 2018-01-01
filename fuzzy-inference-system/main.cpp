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

    auto rulesParser = make_shared<RulesParser>(variableParser->getInputVariables(),
                                                variableParser->getOutputVariables(),
                                                make_shared<Zadeh::TNorm>());

    rulesParser->parse(argv[2]);

    auto inputNames = variableParser->getInputNames();
    auto outputNames = variableParser->getOutputNames();

    auto input = make_shared<FuzzyInput>(inputNames);

    map<string, shared_ptr<InferenceSystem>> inferenceSystems;

    for (auto ruleSet : rulesParser->getRules()) {
        inferenceSystems[ruleSet.first] = make_shared<MamdaniInferenceSystem>(ruleSet.second, make_shared<Zadeh::SNorm>(), defuzzifier);
    }


    double inputs[inputNames.size()];

    int index = 0;
    while (cin >> inputs[index]) {

        input->setValue(inputNames[index], make_shared<DomainElement>(DomainElement({inputs[index]})));

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
