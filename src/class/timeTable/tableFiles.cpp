#include "global.h"
#include "timeTable.h"
#include <cstring>
#include <fstream>
#include <iostream>

bool TimeTable::saveToFiles(const string &studyPlanIndex) const {
    saveTable(studyPlanIndex);
    saveCandidate(studyPlanIndex);
    return true;
};
bool TimeTable::saveTable(const string &studyPlanIndex) const {
    const string info = periodsNum + "," + periodMinute;
    const string name = grade + "-" + semester;
    ofstream file("../" + DATA_DIR + "/" + PLANS_DIR + "/" + PLAN_DIR + studyPlanIndex + "/" + TABLE_DIR + name + "/" +
                  "/info.csv");

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