//
// Created by vkolobara on 18.1.2018..
//

#include <iostream>
#include "Backpropagation.h"

void Backpropagation::learn(vector<vector<double>> inputs, vector<double> outputs) {

    for (int j=0; j<inputs.size()*10000; j++) {
        auto i = j % inputs.size();
        double pred = anfis->forward(inputs[i])[0];

        cout << "LOSS AT " << j << ": "<< loss->loss(pred, outputs[i]) << endl;
        learnExample(inputs[i], outputs[i]);
    }


}

void Backpropagation::learnExample(vector<double> inputs, double output) {
    auto w  = anfis->antecedentForward(inputs);
    auto z = anfis->normalizingForward(w);
    auto f  = anfis->consequentForward(inputs, z);
    auto o  = anfis->outputForward(f);

    auto consParams = anfis->getConsequentLayer()->getParams();

    auto dO = o[0] - output;
    auto wSum = 1e-6;

    for (auto val : w) {
        wSum += val;
    }

    for (int i=0; i<anfis->numRules; i++) {
        auto memberships = anfis->antecedentLayer->memberships[i];

        auto dZ = w[i] / wSum;

        vector<double> gradCons(consParams[i].size());

        for (int j=0; j<consParams[i].size()-1; j++) {
            gradCons[j] = 0.1*dO*dZ*inputs[j];
        }

        gradCons[consParams[i].size()-1] = 0.00001*dO*dZ;

        anfis->getConsequentLayer()->setParams(i, gradCons);

        auto dW = 0.0;

        for (int j=0; j<z.size(); j++) {
            dW += w[i]*z[i];
        }

        dW = (wSum * z[i] - dW) / (wSum * wSum);

        vector<vector<double>> gradMemb(memberships.size());

        for (int j=0; j<memberships.size(); j++) {
            gradMemb[j] = memberships[j]->gradients(inputs[j]);
            for (int k=0; k<memberships.size(); k++) {
                if (k!=j) {
                    gradMemb[j][k] += 0.00001 * dO * dW * memberships[k]->valueAt(inputs[k]);
                }
            }
        }

        for (int j=0; j<memberships.size(); j++) {
            memberships[j]->updateParameters(gradMemb[j]);
        }


    }



}

Backpropagation::Backpropagation(ANFIS *anfis, Loss *loss) : anfis(anfis), loss(loss) {}
