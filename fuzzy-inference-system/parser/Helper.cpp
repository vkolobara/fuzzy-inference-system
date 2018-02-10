//
// Created by vkolobara on 12/31/17.
//

#include <iostream>
#include <algorithm>
#include "Helper.h"

MembershipFunction* parseMembershipFunction(string membershipString, string paramsStr) {
    istringstream iss(paramsStr);
    string token;

    vector<double> params;

    while (getline(iss, token, ',')) {
        params.push_back(stod(token));
    }

    MembershipFunction* func;

    if (membershipString == "L") {
        if (params.size() != 2) //TODO: ERROR;
            ;
        func = new LinearMembershipFunction::LMembershipFunction(params[0], params[1]);
    } else if (membershipString == "LAMBDA") {
        if (params.size() != 3) //TODO: ERROR;
            ;
        func = new LinearMembershipFunction::LambdaMembershipFunction(params[0], params[1], params[2]);
    } else if (membershipString == "GAMMA") {
        if (params.size() != 2) //TODO: ERROR;
            ;
        func = new LinearMembershipFunction::GammaMembershipFunction(params[0], params[1]);
    } else if (membershipString == "PI") {
        if (params.size() != 4) //TODO: ERROR
            ;
        func = new LinearMembershipFunction::PiMembershipFunction(params[0], params[1], params[2], params[3]);
    } else if (membershipString == "S") {
        if (params.size() != 4) //TODO: ERROR
            ;
        func = new SmoothMembershipFunction::SMembershipFunction(params[0], params[1], params[2]);
    } else if (membershipString == "GAUSS") {
        if (params.size() != 2) //TODO: ERROR
            ;
        func = new SmoothMembershipFunction::GaussMembershipFunction(params[0], params[1]);
    } else if (membershipString == "SIGMOID") {
        if (params.size() != 3) //TODO: ERROR
            ;
        func = new SmoothMembershipFunction::SigmoidMembershipFunction(params[0], params[1]);
    } else if (membershipString == "EXP") {
        if (params.size() != 2) //TODO: ERROR
            ;
        func = new SmoothMembershipFunction::ExponentialLikeMembershipFunction(params[0], params[1]);
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

Domain* parseDomain(string domainStr) {
    double start, step, end;

    istringstream iss(domainStr);

    string token;

    getline(iss, token, ',');
    start = stod(token);
    getline(iss, token, ',');
    step = stod(token);
    getline(iss, token, ',');
    end = stod(token);

    return new RangeDomain(start, step, end);
}

LanguageTerm* parseTerm(string termString, Domain* domain) {
    vector<string> splitTerm = split(termString, "\t");

    string name = splitTerm[0];

    auto func = parseMembershipFunction(splitTerm[1], splitTerm[2]);

    auto fuzzySet = new CalculatedFuzzySet(func, domain);

    return new LanguageTerm(name, fuzzySet);

}

SimpleClause* parseSimpleClause(string clauseString, map<string, LanguageVariable*> variables) {
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

    FuzzySet* newSet;

    if (modifier == "not") {
        newSet = new NegatedFuzzySet(term->getMeaning(), new Zadeh::Complement());
    } else if (modifier == "very") {
        newSet = new ConcentratedFuzzySet(term->getMeaning());
    } else if (modifier == "around") {
        newSet = new DilatedFuzzySet(term->getMeaning());
    } else {
        newSet = term->getMeaning();
    }

    auto newTerm = new LanguageTerm(term->getName(), newSet);
    return new SimpleClause(newTerm, variable);

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

FuzzySet* parseConsequense(string consequense, map<string, LanguageVariable*> variables) {

    vector<string> consSplit = split(consequense, "=");

    auto varName = trim(consSplit[0]);
    auto termName = trim(consSplit[1]);

    return variables[varName]->getMeaning(termName);
}

