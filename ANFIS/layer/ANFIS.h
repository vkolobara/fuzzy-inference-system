//
// Created by vkolobara on 18.1.2018..
//

#ifndef FUZZY_ANFIS_H
#define FUZZY_ANFIS_H


#include "AntecedentLayer.h"
#include "NormalizingLayer.h"
#include "OutputLayer.h"
#include "ConsequentLayer.h"

struct ANFIS {
    shared_ptr<AntecedentLayer> antecedentLayer;
    shared_ptr<NormalizingLayer> normalizingLayer;
    shared_ptr<ConsequentLayer> consequentLayer;
    shared_ptr<OutputLayer> outputLayer;
    int numRules;
    ANFIS(int numRules, shared_ptr<AntecedentLayer>antecedentLayer, shared_ptr<NormalizingLayer>normalizingLayer, shared_ptr<ConsequentLayer>consequentLayer,
          shared_ptr<OutputLayer>outputLayer);

    vector<double> forward(vector<double> inputs);
    vector<double> antecedentForward(vector<double> inputs);
    vector<double> normalizingForward(vector<double> inputs);
    vector<double> consequentForward(vector<double> startInputs, vector<double> inputs);
    vector<double> outputForward(vector<double> inputs);


    ~ANFIS();

    shared_ptr<AntecedentLayer>getAntecedentLayer() ;

    shared_ptr<NormalizingLayer>getNormalizingLayer() ;

    shared_ptr<ConsequentLayer>getConsequentLayer() ;

    shared_ptr<OutputLayer>getOutputLayer() ;

};


#endif //FUZZY_ANFIS_H
