//
// Created by Vinko Kolobara on 12. 4. 2018..
//

#include "Defuzzifier.h"
#include "Clause.h"

double COADefuzzifier::defuzzify(Clause *clause) {
    auto max = clause->languageVariable->max;
    auto min = clause->languageVariable->min;
    auto frequency = clause->languageVariable->step;
    auto term = clause->languageTerm;

    const auto resolution = (unsigned int) ((max - min) / frequency);
    double sum = 0;
    double sumX = 0;

    double x, mu;

    for (auto i =0; i<resolution; i++) {
        x = min + i * frequency;
        mu = term->membership(x);

        sumX += mu*x;
        sum += mu;
    }

    return sumX / sum;
}

double COADefuzzifier::defuzzify(vector<Clause *> clauses) {
    auto max = clauses.at(0)->languageVariable->max;
    auto min = clauses.at(0)->languageVariable->min;
    auto frequency = clauses.at(0)->languageVariable->step;

    const auto resolution = (unsigned int) ((max - min) / frequency);
    double sum = 0;
    double sumX = 0;

    double x;
    double mu = 1;

    for (auto i =0; i<resolution; i++) {
        x = min + i * frequency;

        for (auto &clause : clauses) {
            auto term = clause->languageTerm;
            mu = (mu <= term->membership(x)) ? mu : term->membership(x);
        }

        sumX += mu*x;
        sum += mu;
    }


    return 0;
}
