//
// Created by vkolobara on 1/3/18.
//

#include "NormalizingLayer.h"

vector<double> NormalizingLayer::forwardPass(vector<double> inputs) {
    auto sum = 0.0;

    for (auto input : inputs) {
        sum += input;
    }

    vector<double> ret;

    if (sum < 1e-6) sum = 1;

    ret.reserve(inputs.size());

    for (auto input : inputs) {
        ret.push_back(input/sum);
    }

    return ret;
}
