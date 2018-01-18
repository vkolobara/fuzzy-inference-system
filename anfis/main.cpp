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
    std::uniform_real_distribution<double> dist(1.0, 10.0);
    vector<vector<AnfisMembershipFunction*>> mems(2);
    vector<AnfisMembershipFunction*> var1(2);
    for (int i=0; i<2; i++){
        var1[i] = new SigmoidMembershipFunction();
        var1[i]->updateParameters({dist(mt), dist(mt)});
    }
    vector<AnfisMembershipFunction*> var2(2);
    for (int i=0; i<2; i++){
        var2[i] = new SigmoidMembershipFunction();
        var2[i]->updateParameters({dist(mt), dist(mt)});
    }
    mems[0]=var1;
    mems[1] =var2;

    auto antecedentLayer = new AntecedentLayer(2, new ProductTNorm(), mems);
    auto normalizingLayer = new NormalizingLayer();
    auto consequentLayer = new ConsequentLayer(2, 2);
    auto outputLayer = new OutputLayer();

    auto anfis = new ANFIS(2, antecedentLayer, normalizingLayer, consequentLayer, outputLayer);
    auto loss = new MSE();

    vector<vector<double>> inputs(1000);
    vector<double> outputs(1000);

    for (int i=0;i<1000; i++) {
        inputs[i] = vector<double>(2);
        inputs[i][0] = dist(mt);
        inputs[i][1] = dist(mt);
        outputs[i] = inputs[i][0] + inputs[i][1];
    }

    Backpropagation backpropagation(anfis, loss);

    backpropagation.learn(inputs, outputs);

    delete anfis;
    delete loss;
    return 0;
}
