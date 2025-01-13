#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "global.h"

bool showPoorGrade() {
    string currentLine, token;
    vector<string> grdArray, tmpArray;
    int tokenNum, i;

    ifstream file("../" + DATA_DIR + "/" + "grade.csv");

    try {
        if (file.is_open()) {
            throw exception();
        }
    } catch (const exception &) {
        cerr << "Fail to open the grade file:" << strerror(errno) << endl;
        return false;
    }

    cout << endl;
    cout << "<Poor Subjects>" << endl;
    getline(file, currentLine);
    cout << "===" << currentLine << "===" << endl;
    while (getline(file, currentLine)) {
        stringstream ss(currentLine);
        tokenNum = -1;
        while (getline(ss, token, ',')) {
            tokenNum++;
            if (tokenNum == 6) {
                if (token.length() == 3 && token[1] == '.') {
                    if (stof(token) <= 2.5)
                        grdArray.push_back(currentLine);
                } else if (!(token.length() == 1 && isalpha(token[0]))) {
                    cout << "Grade Format Error" << endl;
                    file.close();
                    return false;
                }
            }
        }
    }

    cout << "Major Electives" << endl;
    tmpArray = grdArray;
    for (i = 0; i < tmpArray.size(); i++) {
        stringstream ss(tmpArray[i]);
        tokenNum = -1;
        while (getline(ss, token, ',')) {
            tokenNum++;
            if (tokenNum == 2) {
                if (token == "ME") {
                    cout << tmpArray[i] << endl;
                    grdArray.erase(grdArray.begin() + i);
                }
            }
        }
    }

    cout << "The Others" << endl;

    for (const string &s : grdArray) {
        cout << s << endl;
    }

    file.close();
    return true;
}