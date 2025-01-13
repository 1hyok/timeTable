#include "subject.h"

#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>

#include "global.h"
bool Subject::saveToFiles(const string &studyPlanIndex, const string &grade, const string &semester) const {
    const string info = grade + "," + semester + "," + korName + "," + engName + "," + credit + "," + hour;
    ofstream file("../" + DATA_DIR + "/" + PLANS_DIR + "/" + PLAN_DIR + studyPlanIndex + "/" + TABLE_DIR + grade + "-" +
                  semester + "/" + CANDIDATE_DIR + "/" + engName + ".csv");

    try {
        if (!file.is_open()) {
            throw exception();
        }
    } catch (const exception &) {
        cerr << "Fail to open Subject " << engName << " for writing: " << strerror(errno) << endl;
        return false;
    }
    cout << "Saving Subject " << engName + "..." << endl;
    file << info << endl;
    file.close();
    return true;
}