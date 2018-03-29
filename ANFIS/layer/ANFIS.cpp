//
// Created by vkolobara on 18.1.2018..
//

#include <iostream>
#include <utility>
#include "ANFIS.h"

ANFIS::ANFIS(int numRules, shared_ptr<AntecedentLayer>antecedentLayer, shared_ptr<NormalizingLayer>normalizingLayer, shared_ptr<ConsequentLayer>consequentLayer,
             shared_ptr<OutputLayer>outputLayer) : numRules(numRules), antecedentLayer(antecedentLayer), normalizingLayer(normalizingLayer),
                                         consequentLayer(consequentLayer), outputLayer(outputLayer) {}

ANFIS::~ANFIS() {
    delete antecedentLayer;
    delete normalizingLayer;
    delete consequentLayer;
    delete outputLayer;
}

vector<double> ANFIS::forward(vector<double> inputs) {
    vector<double> w  = antecedentForward(inputs);

    vector<double> z = normalizingForward(w);

    vector<double> f  = consequentForward(inputs, z);

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

shared_ptr<AntecedentLayer>ANFIS::getAntecedentLayer() {
    return antecedentLayer;
}

shared_ptr<NormalizingLayer>ANFIS::getNormalizingLayer() {
    return normalizingLayer;
}

shared_ptr<ConsequentLayer>ANFIS::getConsequentLayer() {
    return consequentLayer;
}

shared_ptr<OutputLayer>ANFIS::getOutputLayer() {
    return outputLayer;
};


