//
// Created by vkolobara on 12/31/17.
//

#include <sstream>
#include "../domain/Domain.h"
#include "../domain/RangeDomain.h"
#include "../language_variable/LanguageTerm.h"
#include "../fuzzyset/MembershipFunction.h"
#include "../inference/Clause.h"

shared_ptr<MembershipFunction> parseMembershipFunction(string membershipString, string paramsStr);

vector<string> split(string s, string delimiter);

shared_ptr<Domain> parseDomain(string domainStr);

shared_ptr<LanguageTerm> parseTerm(string termString, shared_ptr<Domain> domain);

shared_ptr<SimpleClause> parseSimpleClause(string clauseString, map<string, shared_ptr<LanguageVariable>> variables);

shared_ptr<FuzzySet> parseConsequense(string consequense, map<string, shared_ptr<LanguageVariable>> variables);

std::string ltrim(std::string s);

std::string rtrim(std::string s);

string trim(string s);

