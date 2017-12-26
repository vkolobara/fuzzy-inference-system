//
// Created by vkolobara on 12.12.2017..
//

#ifndef FUZZY_INFERENCE_SYSTEM_INFERENCESYSTEM_H
#define FUZZY_INFERENCE_SYSTEM_INFERENCESYSTEM_H

#include "FuzzyInput.h"

class InferenceSystem {
public:
    virtual double getConclusion(FuzzyInput fuzzyInput) = 0;
};


#endif //FUZZY_INFERENCE_SYSTEM_INFERENCESYSTEM_H
