#include "timeTable.h"
#include "subject.h"
#include <sstream>

using namespace std;

Subject TimeTable::parseSubject(const string &line) {
    string token;
    vector<string> tokens;

    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }

    Subject s(tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5]);

    return s;
}
bool TimeTable::addToCandidate(const Subject &s) {
    subjects.push_back(s);

    return true;
}