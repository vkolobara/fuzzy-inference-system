//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_NORMALIZINGLAYER_H
#define FUZZY_NORMALIZINGLAYER_H

#include "Layer.h"

struct NormalizingLayer : public Layer {
    vector<double> forwardPass(vector<double> inputs) override;
};


#endif //FUZZY_NORMALIZINGLAYER_H
