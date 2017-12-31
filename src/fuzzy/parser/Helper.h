//
// Created by vkolobara on 12/31/17.
//

#include <sstream>
#include "../domain/Domain.h"
#include "../domain/RangeDomain.h"
#include "../language_variable/LanguageTerm.h"


vector<string> split(string s, string delimiter) {
    vector<string> ret;

    size_t last = 0;
    size_t next = 0;

    while ((next = s.find(delimiter, last)) != string::npos)
    {
        ret.push_back(s.substr(last, next-last));
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

    return make_shared<RangeDomain>(start,step,end);
}

shared_ptr<LanguageTerm> parseTerm(string termString) {
    vector<string> splitTerm = split(termString, "\t");

    auto name = splitTerm[0];

    auto membershipString = splitTerm[1];

}