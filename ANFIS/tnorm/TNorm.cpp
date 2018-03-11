//
// Created by vkolobara on 1/3/18.
//

#include "TNorm.h"

double ProductTNorm::calculateValue(vector<double> inputs) {
    auto val = 1.0;

    for (auto input : inputs) {
        val *= input;
    }

    return val;
}
