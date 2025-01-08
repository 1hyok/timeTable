#include "subject.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "global.h"
bool Subject::saveToFiles(const string &studyPlanIndex, const string &grade, const string &semester) const {
    const string info = grade + "," + semester + "," + korName + "," + engName + "," + credit + "," + hour;
    ofstream file(DATA_PATH + STUDY_PLAN_PATH + "/studyPlan" + studyPlanIndex + TIME_TABLE_PATH + grade + "-" +
                  semester + CANDIDATE_PATH + "/" + engName + ".csv");

    if (!file) {
        cerr << "Fail to open candidate file for writing: " << strerror(errno) << endl;
        return false;
    }
    cout << "Saving Subject " + engName + "..." << endl;
    file << info << endl;
    file.close();
    return true;
}