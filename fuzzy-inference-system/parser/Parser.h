//
// Created by vkolobara on 12/31/17.
//

#ifndef FUZZY_INFERENCE_SYSTEM_PARSER_H
#define FUZZY_INFERENCE_SYSTEM_PARSER_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Parser {
public:
    void parse(string path) {
        ifstream file(path);

        vector<string> lines;
        string line;

        while (getline(file, line)) {
            lines.push_back(line);
            cout << line << endl;
        }

        parseLines(lines);

        file.close();
    };

    virtual void parseLines(vector<string> lines) = 0;
};


#endif //FUZZY_INFERENCE_SYSTEM_PARSER_H
