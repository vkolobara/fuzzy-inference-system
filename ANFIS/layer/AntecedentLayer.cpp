//
// Created by vkolobara on 1/3/18.
//

#include <iostream>
#include <utility>
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

AntecedentLayer::AntecedentLayer(int numRules, shared_ptr<TNorm>tnorm,
                                 vector<vector<shared_ptr<AnfisMembershipFunction>>> memberships) : numRules(
        numRules), tnorm(tnorm), memberships(std::move(memberships)) {}

vector<shared_ptr<AnfisMembershipFunction>> AntecedentLayer::membershipsForRule(int index) {
    return memberships.at(index);
}
