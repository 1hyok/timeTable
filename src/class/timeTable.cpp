#include "timeTable.h"

#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>

#include "global.h"
#include "subject.h"

using namespace std;

bool TimeTable::showTable() const {
    showDays();
    showCells();
    return true;
}
bool TimeTable::showDays() const {
    int i;
    int spaceNum = 10;
    int borderNum = (spaceNum * 2 + 4) * (DAYS_NUM + 1);

    string space(spaceNum, ' ');
    string border(borderNum, '-');

    cout << "Time Table" << endl;
    cout << border << endl;

    cout << "|                      |";
    for (i = 0; i < DAYS_NUM; i++) {
        cout << space << dayNames[i] << space << "|";
    }
    cout << endl;

    cout << border << endl;
    return true;
}
bool TimeTable::showCells() const {
    int row, col;
    int borderNum = 24 * (DAYS_NUM + 1);
    const int pNum = stoi(periodsNum);
    const string space(22, ' ');
    const string border(borderNum, '-');

    for (row = 0; row < pNum; row++) {
        if (row % 2 == 0) {
            for (col = 0; col < DAYS_NUM + 1; col++) {
                cout << "|" << space << "|";
            }
            cout << endl;
        } else
            cout << border << endl;
    }
    return true;
}

bool TimeTable::showCandidate() const { return true; }
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
// Save Funtion
bool TimeTable::saveToFiles(const string &studyPlanIndex) const {
    saveTable(studyPlanIndex);
    saveCandidate(studyPlanIndex);
    return true;
};
bool TimeTable::saveTable(const string &studyPlanIndex) const {
    const string info = periodsNum + "," + periodMinute;
    const string name = grade + "-" + semester;
    ofstream file(DATA_PATH + STUDY_PLAN_PATH + "/studyPlan" + studyPlanIndex + TIME_TABLE_PATH + name + "/info.csv");
    if (!file) {
        cerr << "Fail to open candidate file for writing: " << strerror(errno) << endl;
        return false;
    }

    cout << "Saving Table " + name + "..." << endl;
    file << info << endl;
    file.close();
    return true;
};
bool TimeTable::saveCandidate(const string &studyPlanIndex) const {
    for (const Subject &s : subjects) {
        s.saveToFiles(studyPlanIndex, grade, semester);
    }
    return true;
};