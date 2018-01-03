//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_OUTPUTLAYER_H
#define FUZZY_OUTPUTLAYER_H


#include "Layer.h"

class OutputLayer : public Layer {
public:
    OutputLayer() = default;
    vector<double> forwardPass (vector<double> inputs) override;
};


#endif //FUZZY_OUTPUTLAYER_H
