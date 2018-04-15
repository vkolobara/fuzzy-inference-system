//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#ifndef FUZZY_TIME_SERIES_DEFUZZIFIER_H
#define FUZZY_TIME_SERIES_DEFUZZIFIER_H


#include "../language_variable/LanguageTerm.h"
#include "Clause.h"

struct Defuzzifier {

    Defuzzifier() = default;

    virtual double defuzzify(Clause* clause) = 0;
    virtual double defuzzify(vector<Clause*> clauses) = 0;

};

struct COADefuzzifier : public Defuzzifier{

    COADefuzzifier() = default;

    double defuzzify(Clause *clause) override;
    double defuzzify(vector<Clause*> clauses) override;

};


#endif //FUZZY_TIME_SERIES_DEFUZZIFIER_H
