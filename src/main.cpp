#include <iostream>
#include <memory>
#include "fuzzy/MembershipFunction.cpp"
#include "fuzzy/inference/Clause.h"
#include "fuzzy/domain/RangeDomain.h"

using namespace std;

int main() {
    shared_ptr<MembershipFunction> tallM = make_shared<LinearMembershipFunction::GammaMembershipFunction>(170, 185);
    shared_ptr<MembershipFunction> shortM = make_shared<LinearMembershipFunction::LMembershipFunction>(40, 175);
    shared_ptr<Domain> domain = std::make_shared<RangeDomain>(40,0.01,250);

    shared_ptr<FuzzySet> tallFuzzy = make_shared<CalculatedFuzzySet>(tallM, domain);
    shared_ptr<FuzzySet> shortFuzzy = make_shared<CalculatedFuzzySet>(shortM, domain);


    shared_ptr<LanguageTerm> shortTerm = std::make_shared<LanguageTerm>("short", shortFuzzy);
    shared_ptr<LanguageTerm> tallTerm  = std::make_shared<LanguageTerm>("tall", tallFuzzy);


    vector<shared_ptr<LanguageTerm>> terms = vector<shared_ptr<LanguageTerm>>({shortTerm, tallTerm});

    shared_ptr<LanguageVariable> langVar = std::make_shared<LanguageVariable>("height", domain, terms);

    shared_ptr<Clause> shortClause = std::make_shared<SimpleClause>(shortTerm, langVar);
    shared_ptr<Clause> tallClause = std::make_shared<SimpleClause>(tallTerm, langVar);

    list<string> names {"height"};
    auto input = make_shared<FuzzyInput>(names);

    input->setValue("height", make_shared<DomainElement>(DomainElement({173})));
    cout << "You are short with membership of: " << shortClause->calculateMembership(*input) << endl;
    cout << "You are tall with membership of: " << tallClause->calculateMembership(*input) << endl;

    vector<shared_ptr<Clause>> clauses {shortClause, tallClause};

    shared_ptr<Clause> andClause = std::make_shared<AndClause>(clauses);

    cout << "AndClause membership: " << andClause->calculateMembership(*input);

    return 0;
}
