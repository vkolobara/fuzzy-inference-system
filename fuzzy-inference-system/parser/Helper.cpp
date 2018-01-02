//
// Created by vkolobara on 12/31/17.
//

#include <iostream>
#include <algorithm>
#include "Helper.h"

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
    } else if (membershipString == "PI") {
        if (params.size() != 4) //TODO: ERROR
            ;
        func = make_shared<LinearMembershipFunction::PiMembershipFunction>(params[0], params[1], params[2], params[3]);
    } else if (membershipString == "S") {
        if (params.size() != 4) //TODO: ERROR
            ;
        func = make_shared<SmoothMembershipFunction::SMembershipFunction>(params[0], params[1], params[2]);
    } else if (membershipString == "GAUSS") {
        if (params.size() != 2) //TODO: ERROR
            ;
        func = make_shared<SmoothMembershipFunction::GaussMembershipFunction>(params[0], params[1]);
    } else if (membershipString == "SIGMOID") {
        if (params.size() != 3) //TODO: ERROR
            ;
        func = make_shared<SmoothMembershipFunction::SigmoidMembershipFunction>(params[0], params[1]);
    } else if (membershipString == "EXP") {
        if (params.size() != 2) //TODO: ERROR
            ;
        func = make_shared<SmoothMembershipFunction::ExponentialLikeMembershipFunction>(params[0], params[1]);
    }

    return func;

}

vector<string> split(string s, string delimiter) {
    vector<string> ret;

    size_t last = 0;
    size_t next = 0;

    while ((next = s.find(delimiter, last)) != string::npos) {
        ret.push_back(s.substr(last, next - last));
        last = next + delimiter.size();
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


    return make_shared<LanguageTerm>(name, fuzzySet);

}

shared_ptr<SimpleClause> parseSimpleClause(string clauseString, map<string, shared_ptr<LanguageVariable>> variables) {
    vector<string> clauseSplit = split(clauseString, "=");

    auto varName = trim(clauseSplit[0]);
    auto termName = trim(clauseSplit[1]);

    auto termNameSplit = split(termName, " ");

    string modifier = "";

    if (termNameSplit.size() == 2) {
        termName = trim(termNameSplit[1]);
        modifier = trim(termNameSplit[0]);
    }

    auto variable = variables[varName];
    auto term = variable->getLanguageTerm(termName);

    shared_ptr<FuzzySet> newSet;

    if (modifier == "not") {
        newSet = make_shared<NegatedFuzzySet>(term->getMeaning(), make_shared<Zadeh::Complement>());
    } else if (modifier == "very") {
        newSet = make_shared<ConcentratedFuzzySet>(term->getMeaning());
    } else if (modifier == "around") {
        newSet = make_shared<DilatedFuzzySet>(term->getMeaning());
    } else {
        newSet = term->getMeaning();
    }

    auto newTerm = make_shared<LanguageTerm>(term->getName(), newSet);
    return make_shared<SimpleClause>(newTerm, variable);

}

std::string ltrim(std::string s) {
    auto str = s;
    auto it2 = std::find_if(str.begin(), str.end(),
                            [](char ch) { return !std::isspace<char>(ch, std::locale::classic()); });
    str.erase(str.begin(), it2);
    return str;
}

std::string rtrim(std::string s) {
    auto str = s;
    auto it1 = std::find_if(str.rbegin(), str.rend(),
                            [](char ch) { return !std::isspace<char>(ch, std::locale::classic()); });
    str.erase(it1.base(), str.end());
    return str;
}

string trim(string s) {
    return ltrim(rtrim(s));
}

shared_ptr<FuzzySet> parseConsequense(string consequense, map<string, shared_ptr<LanguageVariable>> variables) {

    vector<string> consSplit = split(consequense, "=");

    auto varName = trim(consSplit[0]);
    auto termName = trim(consSplit[1]);

    return variables[varName]->getMeaning(termName);
}

