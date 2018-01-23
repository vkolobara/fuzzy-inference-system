//
// Created by vkolobara on 1/3/18.
//

#include "OutputLayer.h"

vector<double> OutputLayer::forwardPass(vector<double> inputs) {

    auto output = 0.0;

    for (auto& n : inputs)
        output += n;

    return vector<double>({output});
}

