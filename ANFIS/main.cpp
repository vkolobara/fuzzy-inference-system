//
// Created by vkolobara on 1/1/18.
//

#include <iostream>
#include <random>
#include "layer/ANFIS.h"
#include "membership/GaussMembershipFunction.h"
#include "algorithm/Backpropagation.h"
#include "membership/SigmoidMembershipFunction.h"

int main(int argc, char* argv[]) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(-1,1);
    vector<vector<AnfisMembershipFunction*>> mems(2);
    for (int i=0; i<mems.size(); i++) {
        mems[i] = vector<AnfisMembershipFunction*>{new GaussMembershipFunction(), new GaussMembershipFunction()};
    }

    auto antecedentLayer = new AntecedentLayer(2, new ProductTNorm(), mems);
    auto normalizingLayer = new NormalizingLayer();
    auto consequentLayer = new ConsequentLayer(2, 2);
    auto outputLayer = new OutputLayer();

    auto anfis = new ANFIS(2, antecedentLayer, normalizingLayer, consequentLayer, outputLayer);
    auto loss = new MSE();

    vector<vector<double>> inputs(100);
    vector<double> outputs(100);

    for (int i=0;i<100; i++) {
        inputs[i] = vector<double>(2);
        inputs[i][0] = dist(mt);
        inputs[i][1] = dist(mt);
        //outputs[i] = cos(inputs[i][0]/5)*cos(inputs[i][0]/5)*((inputs[i][0]-1) * (inputs[i][0]-1) + (inputs[i][1]+2) * (inputs[i][1]+2) - 5 * inputs[i][0] * inputs[i][1] + 3);
        outputs[i] = inputs[i][0] + inputs[i][1];

    }

    Backpropagation backpropagation(anfis, loss);

    backpropagation.learn(inputs, outputs);

    delete anfis;
    delete loss;
    return 0;
}
