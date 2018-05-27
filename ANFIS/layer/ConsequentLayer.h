//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_CONSEQUENTLAYER_H
#define FUZZY_CONSEQUENTLAYER_H


#include "Layer.h"

struct ConsequentLayer : public Layer {
    vector<double> startInputs;
    vector<vector<double>> params;
    ConsequentLayer(int numRules, int numInputs);

    ConsequentLayer(const vector<vector<double>> &params);

    vector<double> forwardPass(vector<double> inputs) override;

    const vector<double> &getStartInputs() const;

    void setStartInputs(const vector<double> &startInputs);

    const vector<vector<double>> &getParams() const;

    void setParams(const vector<vector<double>> &params);

    void setParams(int index, const vector<double> &params);
};


#endif //FUZZY_CONSEQUENTLAYER_H
