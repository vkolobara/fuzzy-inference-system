//
// Created by Vinko Kolobara on 15. 4. 2018..
//

#ifndef FUZZY_TIME_SERIES_PARSER_H
#define FUZZY_TIME_SERIES_PARSER_H

#endif //FUZZY_TIME_SERIES_PARSER_H

#include <string>
#include <vector>

using namespace std;

struct Parser {
    virtual void parse(string fileContents) = 0;
};