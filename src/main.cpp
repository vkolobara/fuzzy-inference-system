#include <iostream>
#include <memory>
#include "fuzzy/FuzzySet.cpp"
#include "fuzzy/inference/Clause.h"
#include "fuzzy/domain/DomainRange.h"

using namespace std;

int main() {
    shared_ptr<FuzzySet> tallFuzzy = shared_ptr<FuzzySet>(new LinearFuzzySet::GammaFuzzySet(170, 185));
    shared_ptr<FuzzySet> shortFuzzy = shared_ptr<FuzzySet>(new LinearFuzzySet::LFuzzySet(40, 175));

    shared_ptr<LanguageTerm> shortTerm = shared_ptr<LanguageTerm>(new LanguageTerm("short", shortFuzzy));
    shared_ptr<LanguageTerm> tallTerm  = shared_ptr<LanguageTerm>(new LanguageTerm("tall", tallFuzzy));

    shared_ptr<Domain> domain = shared_ptr<DomainRange>(new DomainRange(40,0.01,250));

    vector<shared_ptr<LanguageTerm>> terms = vector<shared_ptr<LanguageTerm>>({shortTerm, tallTerm});

    shared_ptr<LanguageVariable> langVar = shared_ptr<LanguageVariable>(new LanguageVariable("height", domain, terms));

    shared_ptr<Clause> shortClause = shared_ptr<SimpleClause>(new SimpleClause(shortTerm, langVar));
    shared_ptr<Clause> tallClause = shared_ptr<SimpleClause>(new SimpleClause(tallTerm, langVar));


    list<string> names {"height"};
    FuzzyInput input = FuzzyInput(names);

    input.setValue("height", 163);
    std::cout << "You are short with membership of: " << shortClause->calculateMembership(input) << std::endl;
    std::cout << "You are tall with membership of: " << tallClause->calculateMembership(input);
    return 0;
}
