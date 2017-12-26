#include <iostream>
#include <memory>
#include "fuzzy/MembershipFunction.cpp"
#include "fuzzy/inference/Clause.h"
#include "fuzzy/domain/RangeDomain.h"

using namespace std;

int main() {
    shared_ptr<FuzzySet> tallFuzzy = shared_ptr<FuzzySet>(new LinearFuzzySet::GammaFuzzySet(170, 185));
    shared_ptr<FuzzySet> shortFuzzy = shared_ptr<FuzzySet>(new LinearFuzzySet::LFuzzySet(40, 175));

    shared_ptr<LanguageTerm> shortTerm = std::make_shared<LanguageTerm>("short", shortFuzzy);
    shared_ptr<LanguageTerm> tallTerm  = std::make_shared<LanguageTerm>("tall", tallFuzzy);

    shared_ptr<Domain> domain = std::make_shared<RangeDomain>(40,0.01,250);

    vector<shared_ptr<LanguageTerm>> terms = vector<shared_ptr<LanguageTerm>>({shortTerm, tallTerm});

    shared_ptr<LanguageVariable> langVar = std::make_shared<LanguageVariable>("height", domain, terms);

    shared_ptr<Clause> shortClause = std::make_shared<SimpleClause>(shortTerm, langVar);
    shared_ptr<Clause> tallClause = std::make_shared<SimpleClause>(tallTerm, langVar);

    list<string> names {"height"};
    FuzzyInput input = FuzzyInput(names);

    input.setValue("height", 173);
    cout << "You are short with membership of: " << shortClause->calculateMembership(input) << endl;
    cout << "You are tall with membership of: " << tallClause->calculateMembership(input) << endl;

    vector<shared_ptr<Clause>> clauses {shortClause, tallClause};

    shared_ptr<Clause> andClause = std::make_shared<AndClause>(clauses);

    cout << "AndClause membership: " << andClause->calculateMembership(input);

    return 0;
}
