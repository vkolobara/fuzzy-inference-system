//
// Created by vkolobara on 18.1.2018..
//

#include <iostream>
#include <utility>
#include "ANFIS.h"

ANFIS::ANFIS(int numRules, AntecedentLayer *antecedentLayer, NormalizingLayer *normalizingLayer, ConsequentLayer *consequentLayer,
             OutputLayer *outputLayer) : numRules(numRules), antecedentLayer(antecedentLayer), normalizingLayer(normalizingLayer),
                                         consequentLayer(consequentLayer), outputLayer(outputLayer) {}

ANFIS::~ANFIS() {
    delete antecedentLayer;
    delete normalizingLayer;
    delete consequentLayer;
    delete outputLayer;
}

vector<double> ANFIS::forward(vector<double> inputs) {
    vector<double> w  = antecedentForward(inputs);
    for (auto val : w) {
        cout << val << " ";
    }
    cout << endl << endl;
    vector<double> z = normalizingForward(w);
    for (auto val : z) {
        cout << val << " ";
    }
    cout << endl << endl;
    vector<double> f  = consequentForward(inputs, z);
    for (auto val : f) {
        cout << val << " ";
    }
    cout << endl << endl;
    vector<double> o  = outputForward(f);
    return o;
}

vector<double> ANFIS::antecedentForward(vector<double> inputs) {
   return antecedentLayer->forwardPass(std::move(inputs));
}

vector<double> ANFIS::normalizingForward(vector<double> inputs) {
    return normalizingLayer->forwardPass(std::move(inputs));
}

vector<double> ANFIS::consequentForward(vector<double> startInputs, vector<double> inputs) {
    consequentLayer->setStartInputs(startInputs);
    return consequentLayer->forwardPass(std::move(inputs));
};
vector<double> ANFIS::outputForward(vector<double> inputs) {
    return outputLayer->forwardPass(std::move(inputs));
}

AntecedentLayer *ANFIS::getAntecedentLayer() {
    return antecedentLayer;
}

NormalizingLayer *ANFIS::getNormalizingLayer() {
    return normalizingLayer;
}

ConsequentLayer *ANFIS::getConsequentLayer() {
    return consequentLayer;
}

OutputLayer *ANFIS::getOutputLayer() {
    return outputLayer;
};


