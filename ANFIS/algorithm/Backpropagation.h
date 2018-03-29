//
// Created by vkolobara on 18.1.2018..
//

#ifndef FUZZY_BACKPROPAGATION_H
#define FUZZY_BACKPROPAGATION_H


#include "../layer/ANFIS.h"
#include "../loss/Loss.h"

class Backpropagation {
private:
    shared_ptr<ANFIS> anfis;
    shared_ptr<Loss> loss;
public:
    Backpropagation(shared_ptr<ANFIS>anfis, shared_ptr<Loss>loss);

    void learn(vector<vector<double>> inputs, vector<double> outputs);
    void learnExample(vector<double> inputs, double output);
};


#endif //FUZZY_BACKPROPAGATION_H
