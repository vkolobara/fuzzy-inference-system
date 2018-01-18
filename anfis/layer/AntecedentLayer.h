//
// Created by vkolobara on 1/3/18.
//

#ifndef FUZZY_ANTECEDENTLAYER_H
#define FUZZY_ANTECEDENTLAYER_H


#include <memory>
#include "Layer.h"
#include "../tnorm/TNorm.h"
#include "../membership/AnfisMembershipFunction.h"

class AntecedentLayer : public Layer {
private:
    int numRules;
    TNorm* tnorm;
public:
    vector<vector<AnfisMembershipFunction*>> memberships;
public:
    AntecedentLayer(int numRules, TNorm *tnorm, vector<vector<AnfisMembershipFunction*>> memberships);

    vector<double> forwardPass(vector<double> inputs) override;
    vector<AnfisMembershipFunction*> membershipsForRule(int index);

    virtual ~AntecedentLayer();
};


#endif //FUZZY_ANTECEDENTLAYER_H
