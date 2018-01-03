//
// Created by vkolobara on 1/3/18.
//

#include "AntecedentLayer.h"

vector<double> AntecedentLayer::forwardPass(vector<double> inputs) {
    vector<double> ret;

    for (auto funcs : memberships) {
        vector<double> values;
        for (int i=0; i<funcs.size(); i++) {
            values.push_back(funcs[i]->valueAt(inputs[i]));
        }
        ret.push_back(tnorm->calculateValue(values));
    }

    return ret;
}

AntecedentLayer::~AntecedentLayer() {
    delete tnorm;
}

AntecedentLayer::AntecedentLayer(int numRules, TNorm *tnorm,
                                 const vector<vector<shared_ptr<AnfisMembershipFunction>>> &memberships) : numRules(
        numRules), tnorm(tnorm), memberships(memberships) {}
