//
// Created by vkolobara on 12/31/17.
//

#include <sstream>
#include "../domain/Domain.h"
#include "../domain/RangeDomain.h"
#include "../language_variable/LanguageTerm.h"
#include "../MembershipFunction.h"

shared_ptr<MembershipFunction> parseMembershipFunction(string membershipString, string paramsStr) {
    istringstream iss(paramsStr);
    string token;

    vector<double> params;

    while (getline(iss, token, ',')) {
        params.push_back(stod(token));
    }

    shared_ptr<MembershipFunction> func;

    if (membershipString == "L") {
        if (params.size() != 2) //TODO: ERROR;
            ;
        func = make_shared<LinearMembershipFunction::LMembershipFunction>(params[0], params[1]);
    } else if (membershipString == "LAMBDA") {
        if (params.size() != 3) //TODO: ERROR;
            ;
        func = make_shared<LinearMembershipFunction::LambdaMembershipFunction>(params[0], params[1], params[2]);
    } else if (membershipString == "GAMMA") {
        if (params.size() != 2) //TODO: ERROR;
            ;
        func = make_shared<LinearMembershipFunction::GammaMembershipFunction>(params[0], params[1]);
    }

    return func;

}

vector<string> split(string s, string delimiter) {
    vector<string> ret;

    size_t last = 0;
    size_t next = 0;

    while ((next = s.find(delimiter, last)) != string::npos) {
        ret.push_back(s.substr(last, next - last));
        last = next + 1;
    }

    ret.push_back(s.substr(last));

    return ret;
}

shared_ptr<Domain> parseDomain(string domainStr) {
    double start, step, end;

    istringstream iss(domainStr);

    string token;

    getline(iss, token, ',');
    start = stod(token);
    getline(iss, token, ',');
    step = stod(token);
    getline(iss, token, ',');
    end = stod(token);

    return make_shared<RangeDomain>(start, step, end);
}

shared_ptr<LanguageTerm> parseTerm(string termString, shared_ptr<Domain> domain) {
    vector<string> splitTerm = split(termString, "\t");

    string name = splitTerm[0];


    auto func = parseMembershipFunction(splitTerm[1], splitTerm[2]);

    auto fuzzySet = make_shared<CalculatedFuzzySet>(func, domain);


    return make_shared<LanguageTerm>(name,fuzzySet);

}

