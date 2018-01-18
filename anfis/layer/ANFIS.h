//
// Created by vkolobara on 18.1.2018..
//

#ifndef FUZZY_ANFIS_H
#define FUZZY_ANFIS_H


#include "AntecedentLayer.h"
#include "NormalizingLayer.h"
#include "OutputLayer.h"
#include "ConsequentLayer.h"

class ANFIS {
public:
    AntecedentLayer* antecedentLayer;
    NormalizingLayer* normalizingLayer;
    ConsequentLayer* consequentLayer;
    OutputLayer* outputLayer;
public:
    int numRules;
    ANFIS(int numRules, AntecedentLayer *antecedentLayer, NormalizingLayer *normalizingLayer, ConsequentLayer *consequentLayer,
          OutputLayer *outputLayer);

    vector<double> forward(vector<double> inputs);
    vector<double> antecedentForward(vector<double> inputs);
    vector<double> normalizingForward(vector<double> inputs);
    vector<double> consequentForward(vector<double> startInputs, vector<double> inputs);
    vector<double> outputForward(vector<double> inputs);


    ~ANFIS();

    AntecedentLayer *getAntecedentLayer() ;

    NormalizingLayer *getNormalizingLayer() ;

    ConsequentLayer *getConsequentLayer() ;

    OutputLayer *getOutputLayer() ;

};


#endif //FUZZY_ANFIS_H
