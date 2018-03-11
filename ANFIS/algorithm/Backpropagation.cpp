//
// Created by vkolobara on 18.1.2018..
//

#include <iostream>
#include "Backpropagation.h"

void Backpropagation::learn(vector<vector<double>> inputs, vector<double> outputs) {

    auto lossVal=0.0;
    for (int j = 0; j < inputs.size() * 1000; j++) {
        auto i = j % inputs.size();
        double pred = anfis->forward(inputs[i])[0];

        lossVal += loss->loss(pred, outputs[i]);

        //cout << "REAL: " << outputs[i] << " - PRED: " << pred << endl;
        if (j>0 && i % inputs.size() == 0) {
            cout << "LOSS AT " << j/inputs.size() << ": " << lossVal / inputs.size() << endl << endl;
            lossVal = 0;
        }

        learnExample(inputs[i], outputs[i]);
    }

    cout << "FINAL LOSS: " << lossVal / inputs.size() << endl << endl;


}

void Backpropagation::learnExample(vector<double> inputs, double output) {
    auto w = anfis->antecedentForward(inputs);
    auto z = anfis->normalizingForward(w);
    auto f = anfis->consequentForward(inputs, z);
    auto o = anfis->outputForward(f);

    auto consParams = anfis->consequentLayer->params;

    auto dO = o[0] - output;
    auto wSum = 1e-6;

    for (auto val : w) {
        wSum += val;
    }

    for (int i = 0; i < anfis->numRules; i++) {
        auto memberships = anfis->antecedentLayer->memberships[i];

        auto dZ = w[i] / wSum;

        for (int j = 0; j < consParams[i].size() - 1; j++) {
            anfis->consequentLayer->params[i][j] -= 0.01 * dO * dZ * inputs[j];
        }

        anfis->consequentLayer->params[i][consParams[i].size() - 1] -= 0.01 * dO * dZ;


        auto dW = 0.0;

        for (int j = 0; j < z.size(); j++) {
            dW += w[i] * z[i];
        }

        dW = (wSum * z[i] - dW) / (wSum * wSum);

        vector<double> gradMemb;

        for (int j = 0; j < memberships.size(); j++) {
            gradMemb = memberships[j]->gradients(inputs[j]);
            for (int l = 0; l < memberships[j]->getNumParameters(); l++) {
                gradMemb[l] = 0.0001;
                for (int k = 0; k < memberships.size(); k++) {
                    if (k != j) {
                        gradMemb[l] *= memberships[k]->valueAt(inputs[k]);
                    }
                }
                gradMemb[l] *= dO * dW;
            }
            anfis->antecedentLayer->memberships[i][j]->updateParameters(gradMemb);

        }

    }


}

Backpropagation::Backpropagation(ANFIS *anfis, Loss *loss) : anfis(anfis), loss(loss) {}
