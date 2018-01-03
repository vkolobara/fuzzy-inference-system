//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_LAYER_H
#define FUZZY_LAYER_H

#include <vector>

using namespace std;

class Layer {
public:
    virtual vector<double> forwardPass(vector<double> inputs) = 0;
};


#endif //FUZZY_LAYER_H
