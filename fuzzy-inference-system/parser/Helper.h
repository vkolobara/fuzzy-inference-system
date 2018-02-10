//
// Created by vkolobara on 12/31/17.
//

#include <sstream>
#include "../domain/Domain.h"
#include "../domain/RangeDomain.h"
#include "../language_variable/LanguageTerm.h"
#include "../fuzzyset/MembershipFunction.h"
#include "../inference/Clause.h"

MembershipFunction* parseMembershipFunction(string membershipString, string paramsStr);

vector<string> split(string s, string delimiter);

Domain* parseDomain(string domainStr);

LanguageTerm* parseTerm(string termString, Domain* domain);

SimpleClause* parseSimpleClause(string clauseString, map<string, LanguageVariable*> variables);

FuzzySet* parseConsequense(string consequense, map<string, LanguageVariable*> variables);

std::string ltrim(std::string s);

std::string rtrim(std::string s);

string trim(string s);

