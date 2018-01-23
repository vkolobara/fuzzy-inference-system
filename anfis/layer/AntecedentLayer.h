//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_ANTECEDENTLAYER_H
#define FUZZY_ANTECEDENTLAYER_H


#include <memory>
#include "Layer.h"
#include "../tnorm/TNorm.h"
#include "../membership/AnfisMembershipFunction.h"

struct AntecedentLayer : public Layer {
    int numRules;
    TNorm* tnorm;
    vector<vector<AnfisMembershipFunction*>> memberships;
    AntecedentLayer(int numRules, TNorm *tnorm, vector<vector<AnfisMembershipFunction*>> memberships);

    vector<double> forwardPass(vector<double> inputs) override;
    vector<AnfisMembershipFunction*> membershipsForRule(int index);

    virtual ~AntecedentLayer();
};


#endif //FUZZY_ANTECEDENTLAYER_H
