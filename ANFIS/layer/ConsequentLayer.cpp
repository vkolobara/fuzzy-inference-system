//
// Created by vkolobara on 1/3/18.
//

#include <random>
#include <iostream>
#include "ConsequentLayer.h"

vector<double> ConsequentLayer::forwardPass(vector<double> inputs) {

    vector<double> outputs;

    for (int i=0; i<params.size(); i++) {
        auto rule = params[i];
        double out = rule[rule.size()-1];

        for (int j=0; j<rule.size()-1; j++) {
            out += rule[j] * startInputs[j];
        }

        outputs.push_back(out * inputs[i]);
    }

    return outputs;
}

const vector<double> &ConsequentLayer::getStartInputs() const {
    return startInputs;
}

void ConsequentLayer::setStartInputs(const vector<double> &startInputs) {
    ConsequentLayer::startInputs = startInputs;
}

const vector<vector<double>> &ConsequentLayer::getParams() const {
    return params;
}

void ConsequentLayer::setParams(const vector<vector<double>> &params) {
    ConsequentLayer::params = params;
}

ConsequentLayer::ConsequentLayer(int numRules, int numInputs) {
    params = vector<vector<double>>(numRules);
    std::random_device r;
    std::mt19937 mt(r());
    std::uniform_real_distribution<double> dist(1.0, 10.0);    std::uniform_real_distribution<double> uniform_dist(-1, 1);
    for (int i=0; i<numRules; i++) {
        vector<double> vals(numInputs+1);
        for (int j=0; j<numInputs+1; j++){
            vals[j] = uniform_dist(mt);
        }
        params[i] = vals;
    }

}

void ConsequentLayer::setParams(int index, const vector<double> &params) {
    this->params[index] = params;
}

ConsequentLayer::ConsequentLayer(const vector<vector<double>> &params) : params(params) {}
