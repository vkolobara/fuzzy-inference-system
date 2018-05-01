//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#ifndef FUZZY_TIME_SERIES_ANTECEDENT_H
#define FUZZY_TIME_SERIES_ANTECEDENT_H


#include <vector>
#include "../norm/Norm.h"
#include "../language_variable/LanguageTerm.h"
#include "Clause.h"

struct Antecedent {
    unique_ptr<BaseOperator::TNorm> tnorm;
    std::vector<shared_ptr<Clause>> clauses;

    explicit Antecedent(BaseOperator::TNorm& tnorm);

    void addClause(Clause& term);
    Clause* getClause(size_t index);

    double getActivation();
};


#endif //FUZZY_TIME_SERIES_ANTECEDENT_H
