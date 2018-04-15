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
    BaseOperator::TNorm* tnorm;
    std::vector<Clause*> clauses;

    explicit Antecedent(BaseOperator::TNorm *tnorm);
    ~Antecedent();

    Antecedent* clone() const;

    void addClause(Clause* term);
    Clause* getClause(size_t index);

    double getActivation();
};


#endif //FUZZY_TIME_SERIES_ANTECEDENT_H
