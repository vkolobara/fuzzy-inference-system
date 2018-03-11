//
// Created by vkolobara on 18.1.2018..
//

#include "Loss.h"

double MSE::loss(double pred, double real) {
    auto val = real-pred;
    return val*val;
}
