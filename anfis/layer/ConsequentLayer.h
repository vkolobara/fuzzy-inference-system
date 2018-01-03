//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_CONSEQUENTLAYER_H
#define FUZZY_CONSEQUENTLAYER_H


#include "Layer.h"

class ConsequentLayer : public Layer {
private:
    vector<double> startInputs;
    vector<vector<double>> params;
public:
    ConsequentLayer() = default;
    vector<double> forwardPass(vector<double> inputs) override;

    const vector<double> &getStartInputs() const;

    void setStartInputs(const vector<double> &startInputs);

    const vector<vector<double>> &getParams() const;

    void setParams(const vector<vector<double>> &params);
};


#endif //FUZZY_CONSEQUENTLAYER_H
