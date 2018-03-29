//
// Created by vkolobara on 12/26/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_DEFUZZIFIER_H
#define FUZZY_INFERENCE_SYSTEM_DEFUZZIFIER_H


#include "../fuzzyset/FuzzySet.h"

class Defuzzifier {
public:
    virtual double defuzzify(shared_ptr<FuzzySet> fuzzySet) = 0;
};

class COADefuzzifier : public Defuzzifier {
public:
    double defuzzify(shared_ptr<FuzzySet> fuzzySet) override;
};


#endif //FUZZY_INFERENCE_SYSTEM_DEFUZZIFIER_H
