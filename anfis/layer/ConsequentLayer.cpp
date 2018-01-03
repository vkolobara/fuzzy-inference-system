//
// Created by vkolobara on 1/3/18.
//

#include "ConsequentLayer.h"

vector<double> ConsequentLayer::forwardPass(vector<double> inputs) {

    vector<double> outputs;

    outputs.reserve(params.size());
    for (int i=0; i<params.size(); i++) {
        auto rule = params[i];
        double out = rule[rule.size()-1];

        for (int i=0; i<rule.size()-1; i++) {
            out += rule[i] * startInputs[i];
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
